#include "SmSdk/Gui/ChatGui.hpp"

SMSDK_BEGIN_NAMESPACE

ChatMessage::ChatMessage(
    const std::string_view& author,
    const std::string_view& message
)
    : m_timeStamp(std::time(NULL))
    , m_author(author)
    , m_message(message)
{}

void ChatGui::postMessage(
    const std::string_view& message,
    const std::string_view& author)
{
    m_chatMessageQueue.emplace_back(author, message);
}

SMSDK_END_NAMESPACE