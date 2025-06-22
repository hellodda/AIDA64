#pragma once

//
//mb prigodidtsa no shas v testax
//

//
//namespace winrt::AIDA64::Framework
//{
//    struct ServiceLocator
//    {
//        ServiceLocator() = default;
//        ~ServiceLocator() = default;
//
//       
//        template<typename serviceT>
//        void register_instance(std::shared_ptr<serviceT> instance)
//        {
//            std::lock_guard<std::mutex> lock(m_mutex);
//            std::type_index key{ typeid(std::shared_ptr<serviceT>) };
//            m_shared_instances[key] = std::move(instance);
//        }
//
//        template<typename winrtT>
//        void register_instance(winrt::com_ptr<winrtT> instance)
//        {
//            std::lock_guard<std::mutex> lock(m_mutex);
//            std::type_index key{ typeid(winrt::com_ptr<winrtT>) };
//            m_rt_instances[key] = std::any(instance); 
//        }
//
//     
//        template<typename serviceT, typename F>
//        void register_factory_shared(F factory)
//        {
//            static_assert(std::is_invocable_v<F> && std::is_same_v<std::invoke_result_t<F>, std::shared_ptr<serviceT>>,
//                "Factory must be invocable with no args and return std::shared_ptr<serviceT>");
//            std::lock_guard<std::mutex> lock(m_mutex);
//            std::type_index key{ typeid(std::shared_ptr<serviceT>) };
//            m_shared_factories[key] = [factory]() -> std::shared_ptr<void> {
//                auto p = factory();
//                return std::static_pointer_cast<void>(p);
//                };
//          
//        }
//
//        template<typename winrtT, typename F>
//        void register_factory_winrt(F factory)
//        {
//            static_assert(std::is_invocable_v<F> && std::is_same_v<std::invoke_result_t<F>, winrt::com_ptr<winrtT>>,
//                "Factory must be invocable with no args and return winrt::com_ptr<winrtT>");
//            std::lock_guard<std::mutex> lock(m_mutex);
//            std::type_index key{ typeid(winrt::com_ptr<winrtT>) };
//          
//            m_rt_factories[key] = [factory]() -> std::any {
//                winrt::com_ptr<winrtT> p = factory();
//                return std::any(p);
//                };
//           
//        }
//
//        template<typename T>
//        T get_required_service()
//        {
//            if constexpr (is_shared_ptr_v<T>) {
//            
//                using serviceT = typename shared_ptr_element_t<T>::element_type;
//                std::type_index key{ typeid(std::shared_ptr<serviceT>) };
//                {
//                    std::lock_guard<std::mutex> lock(m_mutex);
//                    auto it = m_shared_instances.find(key);
//                    if (it != m_shared_instances.end()) {
//                        return std::static_pointer_cast<serviceT>(it->second);
//                    }
//                }
//                std::function<std::shared_ptr<void>()> factoryCopy;
//                {
//                    std::lock_guard<std::mutex> lock(m_mutex);
//                    auto itf = m_shared_factories.find(key);
//                    if (itf != m_shared_factories.end()) {
//                        factoryCopy = itf->second;
//                    }
//                }
//                if (factoryCopy) {
//                    auto newInstVoid = factoryCopy();
//                    if (!newInstVoid) {
//                        throw std::runtime_error("ServiceLocator: shared factory returned nullptr for " + std::string(typeid(serviceT).name()));
//                    }
//                    std::lock_guard<std::mutex> lock(m_mutex);
//                    m_shared_instances[key] = newInstVoid;
//                    return std::static_pointer_cast<serviceT>(newInstVoid);
//                }
//                throw std::runtime_error("Service not registered (shared_ptr): " + std::string(typeid(serviceT).name()));
//            }
//            else if constexpr (is_com_ptr_v<T>) {
//                using winrtT = typename com_ptr_element_t<T>::element_type;
//                std::type_index key{ typeid(winrt::com_ptr<winrtT>) };
//                {
//                    std::lock_guard<std::mutex> lock(m_mutex);
//                    auto it = m_rt_instances.find(key);
//                    if (it != m_rt_instances.end()) {
//                        try {
//                            return std::any_cast<winrt::com_ptr<winrtT>>(it->second);
//                        }
//                        catch (const std::bad_any_cast&) {
//                            throw std::runtime_error("ServiceLocator: stored winrt::com_ptr cannot be cast to requested type " + std::string(typeid(winrt::com_ptr<winrtT>).name()));
//                        }
//                    }
//                }
//                std::function<std::any()> factoryCopy;
//                {
//                    std::lock_guard<std::mutex> lock(m_mutex);
//                    auto itf = m_rt_factories.find(key);
//                    if (itf != m_rt_factories.end()) {
//                        factoryCopy = itf->second;
//                    }
//                }
//                if (factoryCopy) {
//                    std::any anyObj = factoryCopy();
//                    try {
//                        winrt::com_ptr<winrtT> p = std::any_cast<winrt::com_ptr<winrtT>>(anyObj);
//                        std::lock_guard<std::mutex> lock(m_mutex);
//                        m_rt_instances[key] = anyObj;
//                        return p;
//                    }
//                    catch (const std::bad_any_cast&) {
//                        throw std::runtime_error("ServiceLocator: winrt factory returned value not castable to requested type " + std::string(typeid(winrt::com_ptr<winrtT>).name()));
//                    }
//                }
//                throw std::runtime_error("Service not registered (winrt::com_ptr): " + std::string(typeid(winrt::com_ptr<winrtT>).name()));
//            }
//            else {
//                static_assert(always_false_v<T>, "ServiceLocator::get_required_service<T> only supports std::shared_ptr<U> or winrt::com_ptr<U>");
//            }
//        }
//
//        template<typename T>
//        bool is_registered() const
//        {
//            if constexpr (is_shared_ptr_v<T>) {
//                using serviceT = typename shared_ptr_element_t<T>::element_type;
//                std::type_index key{ typeid(std::shared_ptr<serviceT>) };
//                std::lock_guard<std::mutex> lock(m_mutex);
//                return m_shared_instances.count(key) || m_shared_factories.count(key);
//            }
//            else if constexpr (is_com_ptr_v<T>) {
//                using winrtT = typename com_ptr_element_t<T>::element_type;
//                std::type_index key{ typeid(winrt::com_ptr<winrtT>) };
//                std::lock_guard<std::mutex> lock(m_mutex);
//                return m_rt_instances.count(key) || m_rt_factories.count(key);
//            }
//            else {
//                static_assert(always_false_v<T>, "ServiceLocator::is_registered<T> only supports std::shared_ptr<U> or winrt::com_ptr<U>");
//            }
//        }
//
//        template<typename T>
//        void clear_instance()
//        {
//            if constexpr (is_shared_ptr_v<T>) {
//                using serviceT = typename shared_ptr_element_t<T>::element_type;
//                std::type_index key{ typeid(std::shared_ptr<serviceT>) };
//                std::lock_guard<std::mutex> lock(m_mutex);
//                m_shared_instances.erase(key);
//            }
//            else if constexpr (is_com_ptr_v<T>) {
//                using winrtT = typename com_ptr_element_t<T>::element_type;
//                std::type_index key{ typeid(winrt::com_ptr<winrtT>) };
//                std::lock_guard<std::mutex> lock(m_mutex);
//                m_rt_instances.erase(key);
//            }
//            else {
//                static_assert(always_false_v<T>, "ServiceLocator::clear_instance<T> only supports std::shared_ptr<U> or winrt::com_ptr<U>");
//            }
//        }
//
//    private:
//        mutable std::mutex m_mutex;
//
//        std::unordered_map<std::type_index, std::shared_ptr<void>> m_shared_instances;
//        std::unordered_map<std::type_index, std::function<std::shared_ptr<void>()>> m_shared_factories;
//
//        std::unordered_map<std::type_index, std::any> m_rt_instances;
//        std::unordered_map<std::type_index, std::function<std::any()>> m_rt_factories;
//
//        template<class>
//        static constexpr bool always_false_v = false;
//
//        template<typename T>
//        struct is_shared_ptr : std::false_type {};
//        template<typename U>
//        struct is_shared_ptr<std::shared_ptr<U>> : std::true_type {};
//        template<typename T>
//        static constexpr bool is_shared_ptr_v = is_shared_ptr<T>::value;
//
//        template<typename T>
//        struct shared_ptr_element;
//        template<typename U>
//        struct shared_ptr_element<std::shared_ptr<U>> { using element_type = U; };
//        template<typename T>
//        using shared_ptr_element_t = shared_ptr_element<T>;
//
//        template<typename T>
//        struct is_com_ptr : std::false_type {};
//        template<typename U>
//        struct is_com_ptr<winrt::com_ptr<U>> : std::true_type {};
//        template<typename T>
//        static constexpr bool is_com_ptr_v = is_com_ptr<T>::value;
//
//        template<typename T>
//        struct com_ptr_element;
//        template<typename U>
//        struct com_ptr_element<winrt::com_ptr<U>> { using element_type = U; };
//        template<typename T>
//        using com_ptr_element_t = com_ptr_element<T>;
//    };
//}
