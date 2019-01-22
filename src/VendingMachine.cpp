#include "VendingMachine.h"
#include <iostream>

VendingMachine::VendingMachine(IMoneyInput* pMoneyInput)
{
    m_state = STATE_IDLE;
    m_pMoneyCounter = pMoneyInput;
}

void VendingMachine::execute()
{
    switch(m_state)
    {
    case STATE_IDLE:
        m_menuInterface.waitStart();
        m_state = STATE_INPUT_SESSION;
        break;

    case STATE_INPUT_SESSION:
        std::cout<<""<<std::endl;
        std::cout<<"-----------------"<<std::endl;
        std::cout<<"Total Money : Rp."<<m_pMoneyCounter->countMoney()<<std::endl;
        std::cout<<"Total Cost : Rp."<<m_itemDispen.getTotalCost()<<std::endl;
        m_state = mapSessionCmdToState(m_menuInterface.waitCommand());
        break;

    case STATE_INSERT_MONEY:
        m_pMoneyCounter->waitMoneyInput();
        m_state = STATE_INPUT_SESSION;
        break;

    case STATE_INPUT_ITEMS:
        m_itemDispen.queueItemDispense(m_menuInterface.waitItemSelection());
        m_state = STATE_INPUT_SESSION;
        break;

    case STATE_CLEAR_ITEMS:
        m_itemDispen.clearQueue();
        m_state = STATE_INPUT_SESSION;
        break;

    case STATE_VIEW_ITEMS:
    {
        uint32_t itemCountList[ItemInfoLUT::NUM_ITEM_TYPE] = {0};
        m_itemDispen.getItemCountList(itemCountList);
        m_menuInterface.printSelectedItems(itemCountList);
        m_state = STATE_INPUT_SESSION;
        break;
    }


    case STATE_PROCESS_PAYMENT:
        if(m_pMoneyCounter->countMoney() < m_itemDispen.getTotalCost())
        {
            std::cout<<"Insufficient Money, Please Input More Money"<<std::endl;
            m_state = STATE_INPUT_SESSION;
        }
        else
        {
            m_state = STATE_DISPENSE_ITEM;
        }
        break;

    case STATE_DISPENSE_ITEM:
        m_itemDispen.dispense();
        if(m_pMoneyCounter->countMoney() > m_itemDispen.getTotalCost())
        {
            m_state = STATE_DISPENSE_CHANGE;
        }
        else
        {
            m_state = STATE_IDLE;
        }
        break;

    case STATE_CANCEL:
        m_itemDispen.clearQueue();
        m_state = STATE_DISPENSE_CHANGE;
        break;

    case STATE_DISPENSE_CHANGE:
        m_pMoneyCounter->substractMoney(m_itemDispen.getTotalCost());
        m_changeDispen.dispense(m_pMoneyCounter->countMoney());
        m_itemDispen.clearQueue();
        m_pMoneyCounter->reset();
        m_state = STATE_IDLE;
        break;
    }
}

VendingMachine::ExecState VendingMachine::mapSessionCmdToState(MenuInterface::CommandType cmd)
{
    ExecState state;

    switch(cmd)
    {
    case MenuInterface::CMD_INSERT_MONEY:
        state = STATE_INSERT_MONEY;
        break;

    case MenuInterface::CMD_SELECT_ITEM:
        state = STATE_INPUT_ITEMS;
        break;

    case MenuInterface::CMD_CLEAR_ITEM:
        state = STATE_CLEAR_ITEMS;
        break;

    case MenuInterface::CMD_VIEW_ITEM:
        state = STATE_VIEW_ITEMS;
        break;

    case MenuInterface::CMD_FINISHED:
        state = STATE_PROCESS_PAYMENT;
        break;

    case MenuInterface::CMD_CANCEL:
        state = STATE_CANCEL;
        break;
    }

    return state;
}
