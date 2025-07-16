#include "pch.h"
#include "critical_section.h"

namespace win32
{
	critical_section::critical_section()
	{
		m_cs = new CRITICAL_SECTION;

		if (!InitializeCriticalSectionEx(m_cs, 0, 0)) {
			DWORD error{ GetLastError() };
			throw std::runtime_error("Failed to initialize critical section. Error code: " + std::to_string(error));
		}
	}

	critical_section::~critical_section()
	{
		if (m_cs)
		{
			delete m_cs;
			m_cs = NULL;
		}
	}

	void critical_section::lock() noexcept
	{
		if (!m_cs) throw HRESULT(E_ABORT);

		EnterCriticalSection(m_cs);
	}

	bool critical_section::try_lock() noexcept
	{
		if (!m_cs) return false;

		return TryEnterCriticalSection(m_cs);
	}

	void critical_section::unlock() noexcept
	{
		LeaveCriticalSection(m_cs);
	}
}