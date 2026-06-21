#include "SmSdk/Gui/GuiInterface.hpp"

SMSDK_BEGIN_NAMESPACE

std::shared_ptr<GuiBase> GuiInterface::getGuiBase()
{
    return m_pGuiBase;
}

SMSDK_END_NAMESPACE