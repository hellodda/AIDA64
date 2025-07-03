#pragma once

namespace win32
{
	struct critical_section
	{
		critical_section();
		~critical_section();

		critical_section(const critical_section&) = delete;
		critical_section& operator=(const critical_section&) = delete;

		void lock() noexcept;
		bool try_lock() noexcept;
		void unlock() noexcept;

	private:
		PCRITICAL_SECTION m_cs;
	};
}