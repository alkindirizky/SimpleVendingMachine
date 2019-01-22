#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

#include <IMoneyInput.h>
#include <ItemDispenser.h>
#include <MenuInterface.h>
#include <ChangeDispenser.h>

class VendingMachine
{
    public:
        VendingMachine(IMoneyInput* pMoneyInput);
        void execute();

    private:
        enum ExecState
        {
            STATE_IDLE,
            STATE_INPUT_SESSION,
            STATE_INSERT_MONEY,
            STATE_INPUT_ITEMS,
            STATE_CLEAR_ITEMS,
            STATE_VIEW_ITEMS,
            STATE_PROCESS_PAYMENT,
            STATE_DISPENSE_ITEM,
            STATE_CANCEL,
            STATE_DISPENSE_CHANGE
        };

        ExecState mapSessionCmdToState(MenuInterface::CommandType cmd);

        ExecState m_state;
        IMoneyInput* m_pMoneyCounter;
        ItemDispenser m_itemDispen;
        MenuInterface m_menuInterface;
        ChangeDispenser m_changeDispen;
};

#endif // VENDINGMACHINE_H
