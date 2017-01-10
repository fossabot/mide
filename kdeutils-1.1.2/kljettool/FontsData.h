/**********************************************************************

	--- Dlgedit generated file ---

	File: FontsData.h
	Last generated: Tue Jun 24 22:20:39 1997

	DO NOT EDIT!!!  This file will be automatically
	regenerated by dlgedit.  All changes will be lost.

 *********************************************************************/

#ifndef FontsData_included
#define FontsData_included

#include <qdialog.h>
#include <qcombo.h>
#include <qlined.h>

#include "Data.h"

class FontsData : public QDialog
{
    Q_OBJECT

public:

    FontsData
    (
        QWidget* parent = NULL,
        const char* name = NULL
    );

    virtual ~FontsData();

    Data* data;

public slots:


protected slots:

    virtual void SymbolSetComboSelected(const char*);
    virtual void LanguageComboBoxSelected(const char*);
    virtual void Fontnumberselected(const char*);
    virtual void Pitchselected(const char*);
    virtual void PointSizeselected(const char*);

protected:
    QComboBox* LanguageComboBox;
    QComboBox* SymbolSetCombo;
    QLineEdit* Font;
    QLineEdit* Pitch;
    QLineEdit* PointSize;

};

#endif // FontsData_included
