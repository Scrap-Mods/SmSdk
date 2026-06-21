#include "Smsdk/Character/CharacterManager.hpp"
#include "SmSdk/Character/Character.hpp"

#include "SmSdk/Physics/CharacterPhysicsProxy.hpp"

SMSDK_BEGIN_NAMESPACE

std::uint16_t Character::getWorldId() const
{
	return m_uWorldId;
}

std::uint64_t Character::getOwnerSteamId() const
{
	return m_uOwnerSteamId;
}

std::uint32_t Character::getUnitId() const
{
	return m_uUnitId;
}

boost::uuids::uuid Character::getUuid() const
{
	return m_uuid;
}

boost::uuids::uuid Character::getSelectedToolUuid() const
{
	return m_selectedToolUuid;
}

DirectX::XMFLOAT4 Character::getColor() const
{
	return m_color;
}

std::string_view Character::getNameTag() const
{
	return m_nameTag;
}

DirectX::XMFLOAT3 Character::getPosition() const
{
	const auto v_pos = m_pPhysicsProxy->m_pTickRaycastCollisionObject->getWorldTransform().getOrigin();
	return DirectX::XMFLOAT3(v_pos.x(), v_pos.y(), v_pos.z());
}

DirectX::XMFLOAT3 Character::getVelocity() const
{
	return m_velocity;
}

std::shared_ptr<CharacterGraphics> Character::getGraphics() const
{
	return CharacterManagerClient::GetCharacterGraphics(m_uId);
}

std::shared_ptr<GuiInterface> Character::getNameTagGui() const
{
	auto v_pCharGfx = getGraphics();
	if (v_pCharGfx)
		return v_pCharGfx->m_pNameTagGui;
	else
		return nullptr;
}

float Character::getPitch() const
{
	return m_fPitch;
}

float Character::getYaw() const
{
	return m_fYaw;
}

SMSDK_END_NAMESPACE