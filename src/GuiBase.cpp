#include "SmSdk/Gui/GuiBase.hpp"

SMSDK_BEGIN_NAMESPACE

GuiBase::GuiBase()
    : m_pMainPanel(nullptr)
    , m_pGuiInterface(nullptr)
{}

void GuiBase::initialize()
{ /* implemented by the game */ }

void GuiBase::destroyWidgets()
{ /* implemented by the game */ }

void GuiBase::open()
{ /* implemented by the game */ }

void GuiBase::close()
{ /* implemented by the game */ }

bool GuiBase::isActive()
{
#if defined(SMSDK_ENABLE_MYGUI) || defined(SMSDK_BUILD_DLL)
    return m_pMainPanel && m_pMainPanel->getVisible();
#else
    return false;
#endif
}

void GuiBase::setFocus(const std::string& widget)
{ SMSDK_UNREF(widget); /* implemented by the game */ }

SMSDK_END_NAMESPACE