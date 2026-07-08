#include "SmSdk/Gui/OptionsItemSlider.hpp"
#include "SmSdk/config.hpp"

SMSDK_USE_NAMESPACE

#if defined(SMSDK_ENABLE_MYGUI) || defined(SMSDK_BUILD_DLL)

OptionsItemSlider::OptionsItemSlider(
	MyGUI::Widget* pWidget,
	const std::string_view& caption,
	const float fMinValue,
	const float fMaxValue,
	const std::size_t iScrollRange
)
	: OptionsItemBase()
	, m_pSlider(nullptr)
	, m_pValueTextBox(nullptr)
	, m_fMinValue(fMinValue)
	, m_fMaxValue(fMaxValue)
	, m_uSteps(iScrollRange)
{
	this->initializeSlider(pWidget, caption);
	m_pSlider->setScrollRange(m_uSteps + 1);
}

void OptionsItemSlider::initializeSlider(
	MyGUI::Widget* pParent,
	const std::string_view& caption)
{
	MyGUI::LayoutManager::getInstance().loadLayout(
		"$GAME_DATA/Gui/Layouts/Options/OptionsItem_Slider.layout", "", pParent);

	pParent->findWidget("Name")->castType<MyGUI::TextBox>()->setCaptionWithReplacing(std::string(caption));

	m_pSlider = pParent->findWidget("Slider")->castType<MyGUI::ScrollBar>();
	m_pValueTextBox = pParent->findWidget("Value")->castType<MyGUI::TextBox>();
}

void OptionsItemSlider::updateValueText()
{
	m_pValueTextBox->setCaption(std::to_string(m_pSlider->getScrollPosition()));
}

float OptionsItemSlider::getFraction() const
{
	const float v_fFraction = float(m_pSlider->getScrollPosition()) / float(m_uSteps);
	return std::lerp(m_fMinValue, m_fMaxValue, v_fFraction);
}

void OptionsItemSlider::update()
{}

#endif