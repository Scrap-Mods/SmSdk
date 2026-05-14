#include "SmSdk/Gui/CompoundButton.hpp"

SMSDK_BEGIN_NAMESPACE

std::shared_ptr<CompoundButton> CompoundButton::New(MyGUI::Widget* pBaseWidget)
{
	return std::make_shared<CompoundButton>(pBaseWidget);
}

CompoundButton::CompoundButton(
	MyGUI::Widget* pBaseWidget
)
	: m_pBaseWidget(pBaseWidget)
	, m_pButton(pBaseWidget->isType<MyGUI::Button>() ? reinterpret_cast<MyGUI::Button*>(pBaseWidget) : nullptr)
{
	m_pBaseWidget->eventMouseSetFocus += MyGUI::newDelegate(this, &CompoundButton::mouseSetFocusCallback);
	m_pBaseWidget->eventMouseLostFocus += MyGUI::newDelegate(this, &CompoundButton::mouseLostFocusCallback);

	m_pBaseWidget->eventMouseButtonPressed += MyGUI::newDelegate(this, &CompoundButton::mouseButtonPressedCallback);
	m_pBaseWidget->eventMouseButtonReleased += MyGUI::newDelegate(this, &CompoundButton::mouseButtonReleasedCallback);

	m_pBaseWidget->eventMouseButtonClick += MyGUI::newDelegate(this, &CompoundButton::mouseButtonClickCallback);

	if (m_pBaseWidget->getUserData<MyGUI::Any>(false) == nullptr)
		m_pBaseWidget->setUserData(this);
}

void CompoundButton::setColorInherited(
	MyGUI::Widget* pWidget,
	const MyGUI::Colour& color)
{
	const std::string& v_inheritColor = pWidget->getUserString("Cmpnd_InheritColor");
	const bool v_isDisabled = v_inheritColor == std::string_view("false");

	if (!v_isDisabled)
	{
		if (pWidget->isType<MyGUI::TextBox>())
			reinterpret_cast<MyGUI::TextBox*>(pWidget)->setTextColour(color);
		else
			pWidget->setColour(color);
	}
}

void CompoundButton::update()
{
	if (!m_pButton)
		return;

	const std::size_t v_childCount = m_pBaseWidget->getChildCount();
	for (std::size_t a = 0; a < v_childCount; a++)
	{
		MyGUI::Widget* v_pCurChild = m_pBaseWidget->getChildAt(a);
		CompoundButton::setColorInherited(v_pCurChild, m_pButton->getTextColour());

		if (v_pCurChild->getTypeName() == std::string_view("Button"))
			reinterpret_cast<MyGUI::Button*>(v_pCurChild)->setStateSelected(m_pButton->getStateSelected());
	}
}

void CompoundButton::mouseSetFocusCallback(
	MyGUI::Widget* _sender,
	MyGUI::Widget* _old)
{
	const std::size_t v_childCount = m_pBaseWidget->getChildCount();
	for (std::size_t a = 0; a < v_childCount; a++)
	{
		MyGUI::Widget* v_pCurChild = m_pBaseWidget->getChildAt(a);
		
		if (v_pCurChild->getTypeName() == std::string_view("Button"))
		{
			if (m_pButton)
				CompoundButton::setColorInherited(v_pCurChild, m_pButton->getTextColour());
		}
		else
		{
			v_pCurChild->_riseMouseSetFocus(_old);
		}
	}
}

void CompoundButton::mouseLostFocusCallback(
	MyGUI::Widget* _sender,
	MyGUI::Widget* _new)
{
	const std::size_t v_childCount = m_pBaseWidget->getChildCount();
	for (std::size_t a = 0; a < v_childCount; a++)
	{
		MyGUI::Widget* v_pCurChild = m_pBaseWidget->getChildAt(a);

		if (v_pCurChild->getTypeName() == std::string_view("Button"))
		{
			if (m_pButton)
				CompoundButton::setColorInherited(v_pCurChild, m_pButton->getTextColour());
		}
		else
		{
			v_pCurChild->_riseMouseLostFocus(_new);
		}
	}
}

void CompoundButton::mouseButtonPressedCallback(
	MyGUI::Widget* _sender,
	const int _left,
	const int _top,
	const MyGUI::MouseButton _id)
{
	const std::size_t v_childCount = m_pBaseWidget->getChildCount();
	for (std::size_t a = 0; a < v_childCount; a++)
	{
		MyGUI::Widget* v_pCurChild = m_pBaseWidget->getChildAt(a);

		if (v_pCurChild->getTypeName() == std::string_view("Button"))
		{
			if (m_pButton)
				CompoundButton::setColorInherited(v_pCurChild, m_pButton->getTextColour());
		}
		else
		{
			v_pCurChild->_riseMouseButtonPressed(_left, _top, _id);
		}
	}
}

void CompoundButton::mouseButtonReleasedCallback(
	MyGUI::Widget* _sender,
	const int _left,
	const int _top,
	const MyGUI::MouseButton _id)
{
	const std::size_t v_childCount = m_pBaseWidget->getChildCount();
	for (std::size_t a = 0; a < v_childCount; a++)
	{
		MyGUI::Widget* v_pCurChild = m_pBaseWidget->getChildAt(a);

		if (v_pCurChild->getTypeName() == std::string_view("Button"))
		{
			if (m_pButton)
				CompoundButton::setColorInherited(v_pCurChild, m_pButton->getTextColour());
		}
		else
		{
			v_pCurChild->_riseMouseButtonReleased(_left, _top, _id);
		}
	}
}

void CompoundButton::mouseButtonClickCallback(MyGUI::Widget* _sender)
{
	const std::size_t v_childCount = m_pBaseWidget->getChildCount();
	for (std::size_t a = 0; a < v_childCount; a++)
	{
		MyGUI::Widget* v_pCurChild = m_pBaseWidget->getChildAt(a);
		v_pCurChild->_riseMouseButtonClick();

		if (m_pButton)
		{
			CompoundButton::setColorInherited(v_pCurChild, m_pButton->getTextColour());

			if (v_pCurChild->getTypeName() == std::string_view("Button"))
				reinterpret_cast<MyGUI::Button*>(v_pCurChild)->setStateSelected(m_pButton->getStateSelected());
		}
	}
}

SMSDK_END_NAMESPACE