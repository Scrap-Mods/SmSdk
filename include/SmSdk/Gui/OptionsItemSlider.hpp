#pragma once

#include "SmSdk/Gui/OptionsItemBase.hpp"

#include "SmSdk/Util/Memory.hpp"
#include "SmSdk/offsets.hpp"

#include <functional>
#include <string>

SMSDK_BEGIN_NAMESPACE

class OptionsItemSlider : public OptionsItemBase
{
public:
	virtual ~OptionsItemSlider() = default;

#if defined(SMSDK_ENABLE_MYGUI)
	OptionsItemSlider(
	    MyGUI::Widget* pWidget,
	    const std::string& caption,
	    float fMinValue,
	    float fMaxValue,
	    size_t iScrollRange);

	void initializeSlider(MyGUI::Widget* pParent, const std::string& caption);
	void updateValueText();
	float getFraction() const;
#endif

	void update() override {}
public:
	MyGUI::ScrollBar* m_pSlider;
	MyGUI::TextBox* m_pValueTextBox;
	size_t m_uSteps;
	float m_fMinValue;
	float m_fMaxValue;
};

static_assert(offsetof(OptionsItemSlider, OptionsItemSlider::m_pSlider) == 0x10, "OptionsItemSlider::m_pSlider: Incorrect offset");

SMSDK_END_NAMESPACE