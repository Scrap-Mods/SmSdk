#include "SmSdk/Gui/RadioButtonSet.hpp"
#include "SmSdk/Gui/CompoundButton.hpp"

SMSDK_BEGIN_NAMESPACE

std::shared_ptr<RadioButtonSet> RadioButtonSet::New(
    const std::vector<MyGUI::Button*>& vecButtons,
    const std::function<void(MyGUI::Widget*)>& clickCallback)
{
    return std::make_shared<RadioButtonSet>(vecButtons, clickCallback);
}

std::shared_ptr<RadioButtonSet> RadioButtonSet::New(
    const std::vector<MyGUI::Button*>& vecButtons)
{
    return std::make_shared<RadioButtonSet>(vecButtons, [](MyGUI::Widget*) {});
}

RadioButtonSet::RadioButtonSet(
    const std::vector<MyGUI::Button*>& vecButtons,
    const std::function<void(MyGUI::Widget*)>& clickCallback
)
    : m_pSelectedButton(nullptr)
    , m_vecButtons(vecButtons)
    , m_pClickCallback(clickCallback)
{
    for (MyGUI::Button* v_pCurButton : m_vecButtons)
        v_pCurButton->eventMouseButtonClick += MyGUI::newDelegate(this, &RadioButtonSet::onItemMouseClick);

    this->updateSelection();
}

void RadioButtonSet::ChangeButtonState(
    MyGUI::Button* pButton,
    const bool newState)
{
    pButton->setStateSelected(newState);

    CompoundButton* v_pCompoundBtn = pButton->getUserData<CompoundButton>(false);
    if (v_pCompoundBtn)
        v_pCompoundBtn->update();
}

void RadioButtonSet::updateSelection()
{
    MyGUI::Button* v_pPrevSelectedButton = m_pSelectedButton;
    m_pSelectedButton = nullptr;

    for (MyGUI::Button* v_pCurBtn : m_vecButtons)
    {
        if (m_pSelectedButton)
        {
            if (v_pCurBtn->getStateSelected())
                RadioButtonSet::ChangeButtonState(v_pCurBtn, false);
        }
        else if (v_pCurBtn->getStateSelected())
        {
            m_pSelectedButton = v_pCurBtn;
            RadioButtonSet::ChangeButtonState(v_pCurBtn, true);
        }
    }

    if (m_pSelectedButton)
    {
        if (m_pSelectedButton != v_pPrevSelectedButton)
            m_pClickCallback(m_pSelectedButton);
    }
    else if (!m_vecButtons.empty()) // The game does not perform this check. But we do just in case
    {
        // If none of the buttons were active we activate the first one
        m_vecButtons[0]->_riseMouseButtonClick();
    }
}

void RadioButtonSet::onItemMouseClick(MyGUI::Widget* _sender)
{
    if (_sender == m_pSelectedButton)
        return;

    MyGUI::Button* v_pSenderBtn = _sender->castType<MyGUI::Button>();
    RadioButtonSet::ChangeButtonState(v_pSenderBtn, true);

    if (m_pSelectedButton)
        RadioButtonSet::ChangeButtonState(m_pSelectedButton, false);

    m_pSelectedButton = v_pSenderBtn;
    m_pClickCallback(v_pSenderBtn);
}

SMSDK_END_NAMESPACE