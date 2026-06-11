#include "SmSdk/Network/SteamNetworkServer.hpp"

SMSDK_BEGIN_NAMESPACE

std::shared_ptr<SteamNetworkSend> SteamNetworkServer::getNetworkSend()
{
    return std::static_pointer_cast<SteamNetworkSend, NetworkSendInterface>(m_pNetworkSend);
}

SMSDK_END_NAMESPACE