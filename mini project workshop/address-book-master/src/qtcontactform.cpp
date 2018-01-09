#include <QLabel>
#include <QLineEdit>
#include <QFormLayout>
#include "qtcontactform.h"



QtContactForm::QtContactForm(QWidget *parent) : 
        QFormLayout(parent), firstNameField(new QLineEdit()),
        lastNameField(new QLineEdit()),
        addressField(new QLineEdit()),
        phoneNumberField(new QLineEdit()),
        emailField(new QLineEdit()),
        cityField(new QLineEdit())
{
    addRow("<font style='color:blue'>First Name</font>", firstNameField);
    addRow("<font style='color:blue'>Last Name</font>", lastNameField);
    addRow("<font style='color:blue'>Address</font>", addressField);
    addRow("<font style='color:blue'>Phone Number</font>", phoneNumberField);
    addRow("<font style='color:blue'>Email</font>", emailField);
    addRow("<font style='color:blue'>City</font>", cityField);
    }

void QtContactForm::clear()
{
    firstNameField->setText("");
    lastNameField->setText("");
    addressField->setText("");
    phoneNumberField->setText("");
    cityField->setText("");
    emailField->setText("");
}
