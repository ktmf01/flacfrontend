///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wizard.h"

///////////////////////////////////////////////////////////////////////////

wizard::wizard( wxWindow* parent, wxWindowID id, const wxString& title, const wxBitmap& bitmap, const wxPoint& pos, long style )
{
	this->Create( parent, id, title, bitmap, pos, style );

	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxWizardPageSimple* wizp_input = new wxWizardPageSimple( this, NULL, NULL, wxBitmap( wxT("wizardbanner step 1.png"), wxBITMAP_TYPE_ANY ) );
	m_pages.Add( wizp_input );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	m_staticText1 = new wxStaticText( wizp_input, wxID_ANY, wxT("Select input files"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer1->Add( m_staticText1, 0, wxALL, 5 );

	m_filePicker1 = new wxFilePickerCtrl( wizp_input, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.*"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE );
	bSizer1->Add( m_filePicker1, 0, wxALL, 5 );


	wizp_input->SetSizer( bSizer1 );
	wizp_input->Layout();
	bSizer1->Fit( wizp_input );
	wxWizardPageSimple* wizp_operation = new wxWizardPageSimple( this, NULL, NULL, wxBitmap( wxT("wizardbanner step 2.png"), wxBITMAP_TYPE_ANY ) );
	m_pages.Add( wizp_operation );

	wizp_operation->Hide();

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );

	book_operation = new wxSimplebook( wizp_operation, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	book_operation_flac = new wxPanel( book_operation, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	m_staticText2 = new wxStaticText( book_operation_flac, wxID_ANY, wxT("Input consists of FLAC files. What would you like to do?"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer2->Add( m_staticText2, 0, wxALL, 5 );


	bSizer2->Add( 0, 0, 1, wxEXPAND, 5 );

	m_radioBtn1 = new wxRadioButton( book_operation_flac, wxID_ANY, wxT("Re-encode"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
	bSizer2->Add( m_radioBtn1, 0, wxALL, 5 );

	m_radioBtn2 = new wxRadioButton( book_operation_flac, wxID_ANY, wxT("Decode"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_radioBtn2, 0, wxALL, 5 );

	m_radioBtn3 = new wxRadioButton( book_operation_flac, wxID_ANY, wxT("Verify integrity"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_radioBtn3, 0, wxALL, 5 );

	m_radioBtn4 = new wxRadioButton( book_operation_flac, wxID_ANY, wxT("Show audio MD5 sum"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_radioBtn4, 0, wxALL, 5 );


	bSizer2->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer2->Add( 0, 0, 1, wxEXPAND, 5 );


	book_operation_flac->SetSizer( bSizer2 );
	book_operation_flac->Layout();
	bSizer2->Fit( book_operation_flac );
	book_operation->AddPage( book_operation_flac, wxT("a page"), false );
	book_operation_wavaiff = new wxPanel( book_operation, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxVERTICAL );

	m_staticText21 = new wxStaticText( book_operation_wavaiff, wxID_ANY, wxT("Input consists of WAV and/or AIFF files. FLAC frontend will encode these into FLAC files for you"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( 300 );
	bSizer21->Add( m_staticText21, 0, wxALL, 5 );


	book_operation_wavaiff->SetSizer( bSizer21 );
	book_operation_wavaiff->Layout();
	bSizer21->Fit( book_operation_wavaiff );
	book_operation->AddPage( book_operation_wavaiff, wxT("a page"), false );
	book_operation_raw = new wxPanel( book_operation, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );

	m_staticText7 = new wxStaticText( book_operation_raw, wxID_ANY, wxT("Input file type cannot be determined. Should these files be treated as raw PCM?"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( 300 );
	bSizer11->Add( m_staticText7, 0, wxALL, 5 );


	bSizer11->Add( 0, 0, 1, wxEXPAND, 5 );

	m_checkBox2 = new wxCheckBox( book_operation_raw, wxID_ANY, wxT("Yes, the input files are raw PCM"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_checkBox2, 0, wxALL, 5 );


	bSizer11->Add( 0, 0, 1, wxEXPAND, 5 );

	wxGridSizer* gSizer3;
	gSizer3 = new wxGridSizer( 0, 2, 0, 0 );

	m_staticText8 = new wxStaticText( book_operation_raw, wxID_ANY, wxT("Byte order"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	gSizer3->Add( m_staticText8, 0, wxALL, 5 );

	wxString m_choice1Choices[] = { wxT("Little-endian"), wxT("Big-endian") };
	int m_choice1NChoices = sizeof( m_choice1Choices ) / sizeof( wxString );
	m_choice1 = new wxChoice( book_operation_raw, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice1NChoices, m_choice1Choices, 0 );
	m_choice1->SetSelection( 0 );
	gSizer3->Add( m_choice1, 0, wxALL, 5 );

	m_staticText9 = new wxStaticText( book_operation_raw, wxID_ANY, wxT("Bit depth"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	gSizer3->Add( m_staticText9, 0, wxALL, 5 );

	wxString m_choice2Choices[] = { wxT("8"), wxT("16"), wxT("24") };
	int m_choice2NChoices = sizeof( m_choice2Choices ) / sizeof( wxString );
	m_choice2 = new wxChoice( book_operation_raw, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice2NChoices, m_choice2Choices, 0 );
	m_choice2->SetSelection( 0 );
	gSizer3->Add( m_choice2, 0, wxALL, 5 );

	m_staticText10 = new wxStaticText( book_operation_raw, wxID_ANY, wxT("Number of channels"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	gSizer3->Add( m_staticText10, 0, wxALL, 5 );

	wxString m_choice3Choices[] = { wxT("1"), wxT("2"), wxT("3"), wxT("4"), wxT("5"), wxT("6"), wxT("7"), wxT("8") };
	int m_choice3NChoices = sizeof( m_choice3Choices ) / sizeof( wxString );
	m_choice3 = new wxChoice( book_operation_raw, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice3NChoices, m_choice3Choices, 0 );
	m_choice3->SetSelection( 4 );
	gSizer3->Add( m_choice3, 0, wxALL, 5 );

	m_staticText11 = new wxStaticText( book_operation_raw, wxID_ANY, wxT("Signed/unsigned"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	gSizer3->Add( m_staticText11, 0, wxALL, 5 );

	wxString m_choice4Choices[] = { wxT("Signed"), wxT("Unsigned") };
	int m_choice4NChoices = sizeof( m_choice4Choices ) / sizeof( wxString );
	m_choice4 = new wxChoice( book_operation_raw, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice4NChoices, m_choice4Choices, 0 );
	m_choice4->SetSelection( 0 );
	gSizer3->Add( m_choice4, 0, wxALL, 5 );

	txt_samplerate = new wxStaticText( book_operation_raw, wxID_ANY, wxT("Sample rate"), wxDefaultPosition, wxDefaultSize, 0 );
	txt_samplerate->Wrap( -1 );
	gSizer3->Add( txt_samplerate, 0, wxALL, 5 );

	m_textCtrl3 = new wxTextCtrl( book_operation_raw, wxID_ANY, wxT("44100"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer3->Add( m_textCtrl3, 0, wxALL, 5 );


	bSizer11->Add( gSizer3, 1, wxEXPAND, 5 );


	book_operation_raw->SetSizer( bSizer11 );
	book_operation_raw->Layout();
	bSizer11->Fit( book_operation_raw );
	book_operation->AddPage( book_operation_raw, wxT("a page"), false );

	bSizer14->Add( book_operation, 1, wxEXPAND | wxALL, 5 );


	wizp_operation->SetSizer( bSizer14 );
	wizp_operation->Layout();
	bSizer14->Fit( wizp_operation );
	wxWizardPageSimple* wizp_options = new wxWizardPageSimple( this, NULL, NULL, wxBitmap( wxT("wizardbanner step 3.png"), wxBITMAP_TYPE_ANY ) );
	m_pages.Add( wizp_options );

	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxVERTICAL );

	book_options = new wxSimplebook( wizp_options, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	book_options_encode = new wxPanel( book_options, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	book_options_encode->Enable( false );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );

	wxGridSizer* gSizer6;
	gSizer6 = new wxGridSizer( 0, 2, 0, 0 );

	wxBoxSizer* bSizer211;
	bSizer211 = new wxBoxSizer( wxVERTICAL );


	bSizer211->Add( 0, 4, 1, 0, 5 );

	m_staticText14 = new wxStaticText( book_options_encode, wxID_ANY, wxT("Compression level"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	bSizer211->Add( m_staticText14, 0, wxALL, 5 );


	gSizer6->Add( bSizer211, 1, 0, 5 );

	m_slider1 = new wxSlider( book_options_encode, wxID_ANY, 5, 0, 8, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS|wxSL_HORIZONTAL|wxSL_SELRANGE|wxSL_VALUE_LABEL );
	gSizer6->Add( m_slider1, 0, wxALL, 5 );


	bSizer12->Add( gSizer6, 1, wxEXPAND, 5 );

	m_checkBox5 = new wxCheckBox( book_options_encode, wxID_ANY, wxT("Verify encoding"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox5->SetValue(true);
	bSizer12->Add( m_checkBox5, 0, wxALL, 5 );

	m_checkBox6 = new wxCheckBox( book_options_encode, wxID_ANY, wxT("Calculate replaygain"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_checkBox6, 0, wxALL, 5 );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );


	bSizer13->Add( 20, 0, 1, 0, 5 );

	m_checkBox10 = new wxCheckBox( book_options_encode, wxID_ANY, wxT("Treat all input files as one album"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_checkBox10, 0, wxALL, 5 );


	bSizer12->Add( bSizer13, 0, 0, 0 );

	m_checkBox7 = new wxCheckBox( book_options_encode, wxID_ANY, wxT("Create Ogg-FLAC"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_checkBox7, 0, wxALL, 5 );

	m_checkBox8 = new wxCheckBox( book_options_encode, wxID_ANY, wxT("Keep foreign metadata"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_checkBox8, 0, wxALL, 5 );

	m_checkBox9 = new wxCheckBox( book_options_encode, wxID_ANY, wxT("Delete input files"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_checkBox9, 0, wxALL, 5 );


	bSizer12->Add( 0, 0, 1, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( book_options_encode, wxID_ANY, wxT("Output directory") ), wxVERTICAL );

	m_checkBox12 = new wxCheckBox( sbSizer3->GetStaticBox(), wxID_ANY, wxT("Place output files in same directory as input file"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer3->Add( m_checkBox12, 0, wxALL, 5 );

	m_dirPicker1 = new wxDirPickerCtrl( sbSizer3->GetStaticBox(), wxID_ANY, wxEmptyString, wxT("Select a folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE|wxDIRP_SMALL );
	m_dirPicker1->Enable( false );

	sbSizer3->Add( m_dirPicker1, 0, wxALL|wxEXPAND, 5 );


	bSizer12->Add( sbSizer3, 1, wxEXPAND, 5 );


	book_options_encode->SetSizer( bSizer12 );
	book_options_encode->Layout();
	bSizer12->Fit( book_options_encode );
	book_options->AddPage( book_options_encode, wxT("a page"), false );

	bSizer19->Add( book_options, 1, wxEXPAND | wxALL, 5 );


	wizp_options->SetSizer( bSizer19 );
	wizp_options->Layout();
	bSizer19->Fit( wizp_options );
	wxWizardPageSimple* wizp_convert = new wxWizardPageSimple( this, NULL, NULL, wxBitmap( wxT("wizardbanner step 4.png"), wxBITMAP_TYPE_ANY ) );
	m_pages.Add( wizp_convert );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );

	m_textCtrl4 = new wxTextCtrl( wizp_convert, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxTE_DONTWRAP|wxTE_LEFT|wxTE_MULTILINE );
	m_textCtrl4->SetMinSize( wxSize( 500,800 ) );

	bSizer10->Add( m_textCtrl4, 0, wxALL, 5 );


	wizp_convert->SetSizer( bSizer10 );
	wizp_convert->Layout();
	bSizer10->Fit( wizp_convert );

	this->Centre( wxBOTH );

	for ( unsigned int i = 1; i < m_pages.GetCount(); i++ )
	{
		m_pages.Item( i )->SetPrev( m_pages.Item( i - 1 ) );
		m_pages.Item( i - 1 )->SetNext( m_pages.Item( i ) );
	}

	// Connect Events
	this->Connect( wxID_ANY, wxEVT_WIZARD_PAGE_CHANGING, wxWizardEventHandler( wizard::updateWizardPages ) );
}

wizard::~wizard()
{
	// Disconnect Events
	this->Disconnect( wxID_ANY, wxEVT_WIZARD_PAGE_CHANGING, wxWizardEventHandler( wizard::updateWizardPages ) );

	m_pages.Clear();
}
