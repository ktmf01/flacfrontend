///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/filepicker.h>
#include <wx/sizer.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/radiobut.h>
#include <wx/panel.h>
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/textctrl.h>
#include <wx/simplebook.h>
#include <wx/slider.h>
#include <wx/statbox.h>
#include <wx/wizard.h>
#include <wx/dynarray.h>
WX_DEFINE_ARRAY_PTR( wxWizardPageSimple*, WizardPages );

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class wizard
///////////////////////////////////////////////////////////////////////////////
class wizard : public wxWizard
{
	private:

	protected:
		wxStaticText* m_staticText1;
		wxFilePickerCtrl* m_filePicker1;
		wxSimplebook* book_operation;
		wxPanel* book_operation_flac;
		wxStaticText* m_staticText2;
		wxRadioButton* m_radioBtn1;
		wxRadioButton* m_radioBtn2;
		wxRadioButton* m_radioBtn3;
		wxRadioButton* m_radioBtn4;
		wxPanel* book_operation_wavaiff;
		wxStaticText* m_staticText21;
		wxPanel* book_operation_raw;
		wxStaticText* m_staticText7;
		wxCheckBox* m_checkBox2;
		wxStaticText* m_staticText8;
		wxChoice* m_choice1;
		wxStaticText* m_staticText9;
		wxChoice* m_choice2;
		wxStaticText* m_staticText10;
		wxChoice* m_choice3;
		wxStaticText* m_staticText11;
		wxChoice* m_choice4;
		wxStaticText* txt_samplerate;
		wxTextCtrl* m_textCtrl3;
		wxSimplebook* book_options;
		wxPanel* book_options_encode;
		wxStaticText* m_staticText14;
		wxSlider* m_slider1;
		wxCheckBox* m_checkBox5;
		wxCheckBox* m_checkBox6;
		wxCheckBox* m_checkBox10;
		wxCheckBox* m_checkBox7;
		wxCheckBox* m_checkBox8;
		wxCheckBox* m_checkBox9;
		wxCheckBox* m_checkBox12;
		wxDirPickerCtrl* m_dirPicker1;
		wxTextCtrl* m_textCtrl4;

		// Virtual event handlers, override them in your derived class
		virtual void updateWizardPages( wxWizardEvent& event ) { event.Skip(); }


	public:

		wizard( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxBitmap& bitmap = wxNullBitmap, const wxPoint& pos = wxDefaultPosition, long style = wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX );
		WizardPages m_pages;

		~wizard();

};

