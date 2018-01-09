#include "addressbookview.h"
#include "addressbookmodel.h"
#include "addressbookcontroller.h"
#include "qtaddressbookgui.h"
#include "errorinfo.h"
#include "contact.h"

AddressBookController::AddressBookController(AddressBookModel &d) : dataStore(d)
{
    frontEnd = new QtAddressBookGUI(*this, dataStore);
    dataStore.registerView(frontEnd);

}

void AddressBookController::start()
{
    frontEnd->showUI();
}

AddressBookController::~AddressBookController()
{
    delete frontEnd;
}

ErrorInfo AddressBookController::submitContact(const Contact &c)
{    
    
    if(!c.isValidToAdd())
    {
        return ErrorInfo(ERR_CONTACT_NOT_VALID,
                        "Must Fill Necessary Characters.");
    }

    return dataStore.addContact(c);
    
}

ErrorInfo AddressBookController::deleteContact(const Contact::ContactId id)
{
    return dataStore.deleteContact(id);

}

ErrorInfo AddressBookController::editContact(const Contact::ContactId id, const Contact &c)
{
    if(!c.isValidToAdd())
    {
        return ErrorInfo(ERR_CONTACT_NOT_VALID, 
                "Must Fill Necessary Characters.");
    }

    return dataStore.updateContact(id, c);

}

