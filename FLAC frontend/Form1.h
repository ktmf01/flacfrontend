#pragma once

#include "Advanced_options.h"


namespace FLACfrontend {

	using namespace System;
	using namespace System::Diagnostics;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::IO;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{

	public:
		Form1(void)
		{
			InitializeComponent();
			this->AdvDialog = (gcnew Advanced_options());
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::ListBox^  lstFiles;
	protected: 

	private: System::Windows::Forms::Button^  btnAdd;
	private: System::Windows::Forms::Button^  btnRemove;
	private: System::Windows::Forms::Button^  btnClear;
	private: System::Windows::Forms::OpenFileDialog^  dlgAddFile;
	private: System::Windows::Forms::GroupBox^  gbEncoding;

	private: System::Windows::Forms::TextBox^  textLevel;
	private: System::Windows::Forms::Label^  lblLevel;


	private: System::Windows::Forms::TrackBar^  tbLevel;
	private: System::Windows::Forms::CheckBox^  chkReplayGainAlbum;

	private: System::Windows::Forms::CheckBox^  chkReplayGain;
	private: System::Windows::Forms::CheckBox^  chkVerify;
	private: System::Windows::Forms::FolderBrowserDialog^  dlgOutputDirectory;
	private: System::Windows::Forms::GroupBox^  gbOutputDir;



	private: System::Windows::Forms::Button^  btnSelectDirectory;
	private: System::Windows::Forms::TextBox^  txtOutputDirectory;
	private: System::Windows::Forms::Button^  btnOutputDirSameAsInput;



	private: System::Windows::Forms::Button^  btnEncode;
	private: System::Windows::Forms::Button^  btnDecode;
	private: System::Windows::Forms::Button^  btnTest;
	private: System::Windows::Forms::Button^  btnFingerprint;
	private: System::Windows::Forms::Button^  btnExit;



	private: System::Windows::Forms::GroupBox^  gbGeneral;

	private: System::Windows::Forms::CheckBox^  chkOggFlac;

	private: System::Windows::Forms::CheckBox^  chkDeleteInput;
	private: System::Windows::Forms::CheckBox^  chkKeepForeign;
	private: System::Windows::Forms::GroupBox^  gbDecoding;
	private: System::Windows::Forms::CheckBox^  chkDecodeThroughErrors;



	private: System::Windows::Forms::Button^  btnHelp;

	private: System::Windows::Forms::Button^  btnAdvanced;

	private: Advanced_options^ AdvDialog;
	private: System::Windows::Forms::ToolTip^  ttHelp;




	private: System::ComponentModel::IContainer^  components;




	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->lstFiles = (gcnew System::Windows::Forms::ListBox());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->btnRemove = (gcnew System::Windows::Forms::Button());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->dlgAddFile = (gcnew System::Windows::Forms::OpenFileDialog());
			this->gbEncoding = (gcnew System::Windows::Forms::GroupBox());
			this->chkReplayGainAlbum = (gcnew System::Windows::Forms::CheckBox());
			this->chkReplayGain = (gcnew System::Windows::Forms::CheckBox());
			this->chkVerify = (gcnew System::Windows::Forms::CheckBox());
			this->textLevel = (gcnew System::Windows::Forms::TextBox());
			this->lblLevel = (gcnew System::Windows::Forms::Label());
			this->tbLevel = (gcnew System::Windows::Forms::TrackBar());
			this->dlgOutputDirectory = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->gbOutputDir = (gcnew System::Windows::Forms::GroupBox());
			this->btnOutputDirSameAsInput = (gcnew System::Windows::Forms::Button());
			this->btnSelectDirectory = (gcnew System::Windows::Forms::Button());
			this->txtOutputDirectory = (gcnew System::Windows::Forms::TextBox());
			this->btnEncode = (gcnew System::Windows::Forms::Button());
			this->btnDecode = (gcnew System::Windows::Forms::Button());
			this->btnTest = (gcnew System::Windows::Forms::Button());
			this->btnFingerprint = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->gbGeneral = (gcnew System::Windows::Forms::GroupBox());
			this->chkKeepForeign = (gcnew System::Windows::Forms::CheckBox());
			this->chkOggFlac = (gcnew System::Windows::Forms::CheckBox());
			this->chkDeleteInput = (gcnew System::Windows::Forms::CheckBox());
			this->gbDecoding = (gcnew System::Windows::Forms::GroupBox());
			this->chkDecodeThroughErrors = (gcnew System::Windows::Forms::CheckBox());
			this->btnHelp = (gcnew System::Windows::Forms::Button());
			this->btnAdvanced = (gcnew System::Windows::Forms::Button());
			this->ttHelp = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->gbEncoding->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->tbLevel))->BeginInit();
			this->gbOutputDir->SuspendLayout();
			this->gbGeneral->SuspendLayout();
			this->gbDecoding->SuspendLayout();
			this->SuspendLayout();
			// 
			// lstFiles
			// 
			this->lstFiles->AllowDrop = true;
			this->lstFiles->FormattingEnabled = true;
			this->lstFiles->HorizontalScrollbar = true;
			this->lstFiles->Location = System::Drawing::Point(12, 12);
			this->lstFiles->Name = L"lstFiles";
			this->lstFiles->Size = System::Drawing::Size(393, 134);
			this->lstFiles->TabIndex = 0;
			this->lstFiles->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &Form1::lstFiles_DragDrop);
			this->lstFiles->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &Form1::lstFiles_DragEnter);
			// 
			// btnAdd
			// 
			this->btnAdd->Location = System::Drawing::Point(412, 12);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(75, 23);
			this->btnAdd->TabIndex = 1;
			this->btnAdd->Text = L"&Add files";
			this->ttHelp->SetToolTip(this->btnAdd, L"Add files to be encoded/decoded/checked etc.");
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &Form1::btnAdd_Click);
			// 
			// btnRemove
			// 
			this->btnRemove->Location = System::Drawing::Point(412, 42);
			this->btnRemove->Name = L"btnRemove";
			this->btnRemove->Size = System::Drawing::Size(75, 23);
			this->btnRemove->TabIndex = 2;
			this->btnRemove->Text = L"&Remove file";
			this->ttHelp->SetToolTip(this->btnRemove, L"Remove one file from the list");
			this->btnRemove->UseVisualStyleBackColor = true;
			this->btnRemove->Click += gcnew System::EventHandler(this, &Form1::btnRemove_Click);
			// 
			// btnClear
			// 
			this->btnClear->Location = System::Drawing::Point(412, 72);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(75, 23);
			this->btnClear->TabIndex = 3;
			this->btnClear->Text = L"&Clear filelist";
			this->ttHelp->SetToolTip(this->btnClear, L"Clear the list of files to be encoded/decoded/checked etc.");
			this->btnClear->UseVisualStyleBackColor = true;
			this->btnClear->Click += gcnew System::EventHandler(this, &Form1::btnClear_Click);
			// 
			// dlgAddFile
			// 
			this->dlgAddFile->FileName = L"dlgAddFile";
			this->dlgAddFile->Filter = L"Supported Files|*.wav;*.flac;*.ogg;*.oga|FLAC files|*.flac|WAV files|*.wav|OGG Fi" 
				L"les|*.ogg;*.oga";
			this->dlgAddFile->Multiselect = true;
			this->dlgAddFile->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::dlgAddFile_FileOk);
			// 
			// gbEncoding
			// 
			this->gbEncoding->Controls->Add(this->chkReplayGainAlbum);
			this->gbEncoding->Controls->Add(this->chkReplayGain);
			this->gbEncoding->Controls->Add(this->chkVerify);
			this->gbEncoding->Controls->Add(this->textLevel);
			this->gbEncoding->Controls->Add(this->lblLevel);
			this->gbEncoding->Controls->Add(this->tbLevel);
			this->gbEncoding->Location = System::Drawing::Point(12, 152);
			this->gbEncoding->Name = L"gbEncoding";
			this->gbEncoding->Size = System::Drawing::Size(200, 134);
			this->gbEncoding->TabIndex = 4;
			this->gbEncoding->TabStop = false;
			this->gbEncoding->Text = L"Encoding options";
			// 
			// chkReplayGainAlbum
			// 
			this->chkReplayGainAlbum->AutoSize = true;
			this->chkReplayGainAlbum->Location = System::Drawing::Point(30, 108);
			this->chkReplayGainAlbum->Name = L"chkReplayGainAlbum";
			this->chkReplayGainAlbum->Size = System::Drawing::Size(164, 17);
			this->chkReplayGainAlbum->TabIndex = 5;
			this->chkReplayGainAlbum->Text = L"Treat input files as one album";
			this->ttHelp->SetToolTip(this->chkReplayGainAlbum, L"If set, all input files will be treated");
			this->chkReplayGainAlbum->UseVisualStyleBackColor = true;
			// 
			// chkReplayGain
			// 
			this->chkReplayGain->AutoSize = true;
			this->chkReplayGain->Location = System::Drawing::Point(13, 85);
			this->chkReplayGain->Name = L"chkReplayGain";
			this->chkReplayGain->Size = System::Drawing::Size(128, 17);
			this->chkReplayGain->TabIndex = 4;
			this->chkReplayGain->Text = L"Calculate ReplayGain";
			this->ttHelp->SetToolTip(this->chkReplayGain, L"If set, ReplayGain tags are added");
			this->chkReplayGain->UseVisualStyleBackColor = true;
			this->chkReplayGain->CheckStateChanged += gcnew System::EventHandler(this, &Form1::chkReplayGain_CheckStateChanged);
			// 
			// chkVerify
			// 
			this->chkVerify->AutoSize = true;
			this->chkVerify->Checked = true;
			this->chkVerify->CheckState = System::Windows::Forms::CheckState::Checked;
			this->chkVerify->Location = System::Drawing::Point(13, 61);
			this->chkVerify->Name = L"chkVerify";
			this->chkVerify->Size = System::Drawing::Size(123, 17);
			this->chkVerify->TabIndex = 3;
			this->chkVerify->Text = L"Verify after encoding";
			this->ttHelp->SetToolTip(this->chkVerify, L"If set, the resulting file is checked for integrity");
			this->chkVerify->UseVisualStyleBackColor = true;
			// 
			// textLevel
			// 
			this->textLevel->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textLevel->Location = System::Drawing::Point(48, 27);
			this->textLevel->Name = L"textLevel";
			this->textLevel->ReadOnly = true;
			this->textLevel->Size = System::Drawing::Size(21, 20);
			this->textLevel->TabIndex = 2;
			this->textLevel->Text = L"5";
			this->textLevel->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->ttHelp->SetToolTip(this->textLevel, L"The compression level, a higher level makes smaller files, but takes longer to en" 
				L"code");
			// 
			// lblLevel
			// 
			this->lblLevel->AutoSize = true;
			this->lblLevel->Location = System::Drawing::Point(10, 30);
			this->lblLevel->Name = L"lblLevel";
			this->lblLevel->Size = System::Drawing::Size(36, 13);
			this->lblLevel->TabIndex = 1;
			this->lblLevel->Text = L"Level:";
			// 
			// tbLevel
			// 
			this->tbLevel->Location = System::Drawing::Point(75, 23);
			this->tbLevel->Maximum = 8;
			this->tbLevel->Name = L"tbLevel";
			this->tbLevel->Size = System::Drawing::Size(119, 45);
			this->tbLevel->TabIndex = 0;
			this->ttHelp->SetToolTip(this->tbLevel, L"Set the compression level, a higher level makes smaller files, but takes longer t" 
				L"o encode");
			this->tbLevel->Value = 5;
			this->tbLevel->ValueChanged += gcnew System::EventHandler(this, &Form1::tbLevel_ValueChanged);
			// 
			// gbOutputDir
			// 
			this->gbOutputDir->Controls->Add(this->btnOutputDirSameAsInput);
			this->gbOutputDir->Controls->Add(this->btnSelectDirectory);
			this->gbOutputDir->Controls->Add(this->txtOutputDirectory);
			this->gbOutputDir->Location = System::Drawing::Point(12, 292);
			this->gbOutputDir->Name = L"gbOutputDir";
			this->gbOutputDir->Size = System::Drawing::Size(469, 53);
			this->gbOutputDir->TabIndex = 5;
			this->gbOutputDir->TabStop = false;
			this->gbOutputDir->Text = L"Output directory (only for encoding and decoding)";
			// 
			// btnOutputDirSameAsInput
			// 
			this->btnOutputDirSameAsInput->Location = System::Drawing::Point(375, 21);
			this->btnOutputDirSameAsInput->Name = L"btnOutputDirSameAsInput";
			this->btnOutputDirSameAsInput->Size = System::Drawing::Size(85, 22);
			this->btnOutputDirSameAsInput->TabIndex = 2;
			this->btnOutputDirSameAsInput->Text = L"Same as input";
			this->ttHelp->SetToolTip(this->btnOutputDirSameAsInput, L"Set output directory the same as input directory");
			this->btnOutputDirSameAsInput->UseVisualStyleBackColor = true;
			this->btnOutputDirSameAsInput->Click += gcnew System::EventHandler(this, &Form1::btnOutputDirSameAsInput_Click);
			// 
			// btnSelectDirectory
			// 
			this->btnSelectDirectory->Location = System::Drawing::Point(346, 21);
			this->btnSelectDirectory->Name = L"btnSelectDirectory";
			this->btnSelectDirectory->Size = System::Drawing::Size(26, 22);
			this->btnSelectDirectory->TabIndex = 1;
			this->btnSelectDirectory->Text = L"...";
			this->ttHelp->SetToolTip(this->btnSelectDirectory, L"Select an output directory");
			this->btnSelectDirectory->UseVisualStyleBackColor = true;
			this->btnSelectDirectory->Click += gcnew System::EventHandler(this, &Form1::btnSelectDirectory_Click);
			// 
			// txtOutputDirectory
			// 
			this->txtOutputDirectory->Enabled = false;
			this->txtOutputDirectory->Location = System::Drawing::Point(13, 22);
			this->txtOutputDirectory->Name = L"txtOutputDirectory";
			this->txtOutputDirectory->Size = System::Drawing::Size(327, 20);
			this->txtOutputDirectory->TabIndex = 0;
			this->txtOutputDirectory->Text = L"<< Same as input directory >>";
			// 
			// btnEncode
			// 
			this->btnEncode->Location = System::Drawing::Point(12, 351);
			this->btnEncode->Name = L"btnEncode";
			this->btnEncode->Size = System::Drawing::Size(75, 23);
			this->btnEncode->TabIndex = 6;
			this->btnEncode->Text = L"&Encode";
			this->ttHelp->SetToolTip(this->btnEncode, L"Encode WAV files or re-encode FLAC files to FLAC");
			this->btnEncode->UseVisualStyleBackColor = true;
			this->btnEncode->Click += gcnew System::EventHandler(this, &Form1::btnEncode_Click);
			// 
			// btnDecode
			// 
			this->btnDecode->Location = System::Drawing::Point(107, 351);
			this->btnDecode->Name = L"btnDecode";
			this->btnDecode->Size = System::Drawing::Size(75, 23);
			this->btnDecode->TabIndex = 7;
			this->btnDecode->Text = L"&Decode";
			this->ttHelp->SetToolTip(this->btnDecode, L"Decode FLAC-files to WAV-files");
			this->btnDecode->UseVisualStyleBackColor = true;
			this->btnDecode->Click += gcnew System::EventHandler(this, &Form1::btnDecode_Click);
			// 
			// btnTest
			// 
			this->btnTest->Location = System::Drawing::Point(201, 351);
			this->btnTest->Name = L"btnTest";
			this->btnTest->Size = System::Drawing::Size(90, 23);
			this->btnTest->TabIndex = 8;
			this->btnTest->Text = L"&Test for errors";
			this->ttHelp->SetToolTip(this->btnTest, L"Test whether FLAC-file is not corrupt");
			this->btnTest->UseVisualStyleBackColor = true;
			this->btnTest->Click += gcnew System::EventHandler(this, &Form1::btnTest_Click);
			// 
			// btnFingerprint
			// 
			this->btnFingerprint->Location = System::Drawing::Point(311, 351);
			this->btnFingerprint->Name = L"btnFingerprint";
			this->btnFingerprint->Size = System::Drawing::Size(75, 23);
			this->btnFingerprint->TabIndex = 9;
			this->btnFingerprint->Text = L"&Fingerprint";
			this->ttHelp->SetToolTip(this->btnFingerprint, L"Show MD5 sums of FLAC-files");
			this->btnFingerprint->UseVisualStyleBackColor = true;
			this->btnFingerprint->Click += gcnew System::EventHandler(this, &Form1::btnFingerprint_Click);
			// 
			// btnExit
			// 
			this->btnExit->Location = System::Drawing::Point(406, 351);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(75, 23);
			this->btnExit->TabIndex = 10;
			this->btnExit->Text = L"E&xit";
			this->ttHelp->SetToolTip(this->btnExit, L"Exit FLAC frontend");
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &Form1::btnExit_Click);
			// 
			// gbGeneral
			// 
			this->gbGeneral->Controls->Add(this->chkKeepForeign);
			this->gbGeneral->Controls->Add(this->chkOggFlac);
			this->gbGeneral->Controls->Add(this->chkDeleteInput);
			this->gbGeneral->Location = System::Drawing::Point(220, 152);
			this->gbGeneral->Name = L"gbGeneral";
			this->gbGeneral->Size = System::Drawing::Size(185, 88);
			this->gbGeneral->TabIndex = 11;
			this->gbGeneral->TabStop = false;
			this->gbGeneral->Text = L"General options";
			// 
			// chkKeepForeign
			// 
			this->chkKeepForeign->AutoSize = true;
			this->chkKeepForeign->Location = System::Drawing::Point(13, 66);
			this->chkKeepForeign->Name = L"chkKeepForeign";
			this->chkKeepForeign->Size = System::Drawing::Size(133, 17);
			this->chkKeepForeign->TabIndex = 2;
			this->chkKeepForeign->Text = L"Keep foreign metadata";
			this->ttHelp->SetToolTip(this->chkKeepForeign, L"Keep foreign metadata (like BWF-chunks), see the flac website for more informatio" 
				L"n");
			this->chkKeepForeign->UseVisualStyleBackColor = true;
			// 
			// chkOggFlac
			// 
			this->chkOggFlac->AutoSize = true;
			this->chkOggFlac->Location = System::Drawing::Point(13, 43);
			this->chkOggFlac->Name = L"chkOggFlac";
			this->chkOggFlac->Size = System::Drawing::Size(153, 17);
			this->chkOggFlac->TabIndex = 1;
			this->chkOggFlac->Text = L"Create/read as OGG-FLAC";
			this->ttHelp->SetToolTip(this->chkOggFlac, L"Create a FLAC-file in the OGG container or force the input file to be read as OGG" 
				L"");
			this->chkOggFlac->UseVisualStyleBackColor = true;
			// 
			// chkDeleteInput
			// 
			this->chkDeleteInput->AutoSize = true;
			this->chkDeleteInput->Location = System::Drawing::Point(13, 20);
			this->chkDeleteInput->Name = L"chkDeleteInput";
			this->chkDeleteInput->Size = System::Drawing::Size(104, 17);
			this->chkDeleteInput->TabIndex = 0;
			this->chkDeleteInput->Text = L"Delete input files";
			this->ttHelp->SetToolTip(this->chkDeleteInput, L"Delete the input files after a succesful encode or decode operation");
			this->chkDeleteInput->UseVisualStyleBackColor = true;
			// 
			// gbDecoding
			// 
			this->gbDecoding->Controls->Add(this->chkDecodeThroughErrors);
			this->gbDecoding->Location = System::Drawing::Point(220, 243);
			this->gbDecoding->Name = L"gbDecoding";
			this->gbDecoding->Size = System::Drawing::Size(185, 43);
			this->gbDecoding->TabIndex = 12;
			this->gbDecoding->TabStop = false;
			this->gbDecoding->Text = L"Decoding/testing options";
			// 
			// chkDecodeThroughErrors
			// 
			this->chkDecodeThroughErrors->AutoSize = true;
			this->chkDecodeThroughErrors->Location = System::Drawing::Point(13, 19);
			this->chkDecodeThroughErrors->Name = L"chkDecodeThroughErrors";
			this->chkDecodeThroughErrors->Size = System::Drawing::Size(154, 17);
			this->chkDecodeThroughErrors->TabIndex = 0;
			this->chkDecodeThroughErrors->Text = L"Decode/test through errors";
			this->ttHelp->SetToolTip(this->chkDecodeThroughErrors, L"When errors are found during decoding, do not stop");
			this->chkDecodeThroughErrors->UseVisualStyleBackColor = true;
			// 
			// btnHelp
			// 
			this->btnHelp->Location = System::Drawing::Point(412, 256);
			this->btnHelp->Name = L"btnHelp";
			this->btnHelp->Size = System::Drawing::Size(75, 23);
			this->btnHelp->TabIndex = 13;
			this->btnHelp->Text = L"&Help";
			this->ttHelp->SetToolTip(this->btnHelp, L"Place your mouse pointer over an option to get more information");
			this->btnHelp->UseVisualStyleBackColor = true;
			this->btnHelp->Click += gcnew System::EventHandler(this, &Form1::btnHelp_Click);
			// 
			// btnAdvanced
			// 
			this->btnAdvanced->Location = System::Drawing::Point(411, 167);
			this->btnAdvanced->Name = L"btnAdvanced";
			this->btnAdvanced->Size = System::Drawing::Size(75, 23);
			this->btnAdvanced->TabIndex = 14;
			this->btnAdvanced->Text = L"Ad&vanced";
			this->ttHelp->SetToolTip(this->btnAdvanced, L"See advanced options");
			this->btnAdvanced->UseVisualStyleBackColor = true;
			this->btnAdvanced->Click += gcnew System::EventHandler(this, &Form1::btnAdvanced_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(493, 382);
			this->Controls->Add(this->btnAdvanced);
			this->Controls->Add(this->btnHelp);
			this->Controls->Add(this->gbDecoding);
			this->Controls->Add(this->gbGeneral);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->btnFingerprint);
			this->Controls->Add(this->btnTest);
			this->Controls->Add(this->btnDecode);
			this->Controls->Add(this->btnEncode);
			this->Controls->Add(this->gbOutputDir);
			this->Controls->Add(this->gbEncoding);
			this->Controls->Add(this->btnClear);
			this->Controls->Add(this->btnRemove);
			this->Controls->Add(this->btnAdd);
			this->Controls->Add(this->lstFiles);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"FLAC Frontend";
			this->gbEncoding->ResumeLayout(false);
			this->gbEncoding->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->tbLevel))->EndInit();
			this->gbOutputDir->ResumeLayout(false);
			this->gbOutputDir->PerformLayout();
			this->gbGeneral->ResumeLayout(false);
			this->gbGeneral->PerformLayout();
			this->gbDecoding->ResumeLayout(false);
			this->gbDecoding->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

// -------------------------------//
// --- Right column of buttons --- //
// -------------------------------//

private: System::Void btnAdd_Click(System::Object^  sender, System::EventArgs^  e) {
			 dlgAddFile->ShowDialog();
		 }

private: System::Void dlgAddFile_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			 lstFiles->Items->AddRange(dlgAddFile->FileNames);
		 }

private: System::Void btnClear_Click(System::Object^  sender, System::EventArgs^  e) {
			 lstFiles->Items->Clear();
		 }

private: System::Void btnRemove_Click(System::Object^  sender, System::EventArgs^  e) {
			 lstFiles->Items->Remove(lstFiles->SelectedItem);	 
		 }

private: System::Void btnAdvanced_Click(System::Object^  sender, System::EventArgs^  e) {
			 AdvDialog->ShowDialog();
		 }

private: System::Void btnHelp_Click(System::Object^  sender, System::EventArgs^  e) {
			 ttHelp->Show("Place your mouse pointer over a specific option to get more information",btnHelp);
		 }

// ----------------------------------//
// --- Setting fields interaction --- //
// ----------------------------------//

private: System::Void tbLevel_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 textLevel->Text = tbLevel->Value.ToString();
		 }

private: System::Void chkReplayGain_CheckStateChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(chkReplayGain->Checked == true){
				 chkReplayGainAlbum->Enabled = true;
			 }else{
				 chkReplayGainAlbum->Checked = false;
				 chkReplayGainAlbum->Enabled = false;
			 }

		 }

// ---------------------------------//
// --- Output directory buttons --- //
// ---------------------------------//

private: System::Void btnSelectDirectory_Click(System::Object^  sender, System::EventArgs^  e) {
			 dlgOutputDirectory->ShowDialog();
			 if(!String::IsNullOrEmpty(dlgOutputDirectory->SelectedPath))
				txtOutputDirectory->Text = dlgOutputDirectory->SelectedPath;
		 }

private: System::Void btnOutputDirSameAsInput_Click(System::Object^  sender, System::EventArgs^  e) {
			 txtOutputDirectory->Text = "<< Same as input directory >>";
		 }


// ---------------------------//
// --- Last row of buttons --- //
// ---------------------------//

private: System::Void btnEncode_Click(System::Object^  sender, System::EventArgs^  e) {
			 // Let's first create some kind of BAT-file
			 String ^ batchFileName = Path::GetTempPath() + "flacfrontend.bat";
			 StreamWriter ^ batch = gcnew StreamWriter(batchFileName);
			 String ^ tmpBatch = "";
			 String ^ command = "flac.exe ";
			 String ^ fileTemp = "";
			 String ^ ext = ".flac";
			 int numberOfFiles = lstFiles->Items->Count;
			 int i;

			 // Supress commands and set codepage to unicode
			 batch->WriteLine("@ECHO OFF");
			 batch->WriteLine("chcp 65001");

			 // Check whether possible
			 if(chkReplayGain->Checked == true && chkReplayGainAlbum->Checked == true && numberOfFiles > 50){
				 MessageBox::Show("Adding Album ReplayGain for more then 50 files is not possible","Too many files",MessageBoxButtons::OK,MessageBoxIcon::Error);
				 return;
			 }

			 // Retrieve settings and transform to command-line options
			 command += "-" + tbLevel->Value.ToString() + " ";
			 if(chkVerify->Checked == true)		command += "-V ";
			 if(chkDeleteInput->Checked == true)	command += "--delete-input-file ";
			 if(chkKeepForeign->Checked == true)	command += "--keep-foreign-metadata ";
			 if(chkOggFlac->Checked == true){	    command += "--ogg "; ext = ".oga"; }
			 if(AdvDialog->chkIgnoreChunkSize->Checked == true)	    command += "--ignore-chunk-sizes ";
			 if(chkReplayGain->Checked == true && chkReplayGainAlbum->Checked == false)
				 command += "--replay-gain ";
			 if(!String::IsNullOrEmpty(AdvDialog->txtCuesheet->Text))
				  command += "--cuesheet " + AdvDialog->txtCuesheet->Text + " ";

			  command += AdvDialog->txtCommandLine->Text + " ";

			  
			  if(txtOutputDirectory->Text != "<< Same as input directory >>"){
				  // Proces each file seperate if output directory is specified
				  for(i=0; i<numberOfFiles; i++){
					  fileTemp = "" + lstFiles->Items[i];
					  fileTemp = txtOutputDirectory->Text + "\\" + fileTemp->Substring(fileTemp->LastIndexOf("\\"));
					  fileTemp = fileTemp->Substring(0,fileTemp->LastIndexOf(".")) + ext;
					  batch->WriteLine(command + "-o " + "\"" + fileTemp + "\" \"" + lstFiles->Items[i] + "\"");
				  }
			  } else if(chkReplayGain->Checked == true && chkReplayGainAlbum->Checked == false){
				  // Proces files in batches of 50 if output directory is same as input
				  // and (not-album) ReplayGain processing is required
				  for(i=0; i<numberOfFiles; i++){
					  if (i % 50 == 0){
						  batch->WriteLine(tmpBatch);
						  tmpBatch = command;
					  }
					  tmpBatch += "\"" + lstFiles->Items[i] + "\" ";
				  }
				  batch->WriteLine(tmpBatch);
			  } else {
				  // Proces files in batches of 50 if output directory is same as input
				  // and ReplayGain processing is not required or Album gain has to be calculated seperately
				  for(i=0; i<numberOfFiles; i++){
					  if (i % 50 == 0){
						  batch->WriteLine(tmpBatch);
						  tmpBatch = command;
					  }
					  tmpBatch += "\"" + lstFiles->Items[i] + "\" ";
				  }
				  batch->WriteLine(tmpBatch);
			  }

			 // Add ReplayGain tags if album-tags have to be added 
		     if(chkReplayGain->Checked == true && chkReplayGainAlbum->Checked == true){
				 batch->WriteLine("ECHO Now adding ReplayGain, this can take a while... ");
				 tmpBatch = "metaflac --add-replay-gain ";
				 for(i=0; i<numberOfFiles; i++){
					 fileTemp = "" + lstFiles->Items[i];
					 fileTemp = fileTemp->Substring(0,fileTemp->LastIndexOf(".")) + ext;
					 tmpBatch += "\"" + fileTemp + "\" ";
				 }
				 batch->WriteLine(tmpBatch);
			 }

			 // Add pause to let console window stay 
			 batch->WriteLine("PAUSE");
			 // Close file, otherwise it won't execute
			 batch->Close();

			 // Execute batch-file
			 Process::Start(batchFileName);
		 }

private: System::Void btnDecode_Click(System::Object^  sender, System::EventArgs^  e) {
			 // Let's first create some kind of BAT-file
			 String ^ batchFileName = Path::GetTempPath() + "flacfrontend.bat";
			 StreamWriter ^ batch = gcnew StreamWriter(batchFileName);
			 String ^ tmpBatch = "";
			 String ^ command = "flac.exe -d ";
			 String ^ fileTemp = "";
			 int numberOfFiles = lstFiles->Items->Count;
			 int i;

			 // Supress commands and set codepage to unicode
			 batch->WriteLine("@ECHO OFF");
			 batch->WriteLine("chcp 65001");

			 // Retrieve settings
			  if(chkDeleteInput->Checked == true)	command += "--delete-input-file ";
			  if(chkKeepForeign->Checked == true)	command += "--keep-foreign-metadata ";
			  if(chkOggFlac->Checked == true)	    command += "--ogg ";
			  if(chkDecodeThroughErrors->Checked == true)	    command += "-F ";

			  command += AdvDialog->txtCommandLine->Text + " ";


			  if(txtOutputDirectory->Text != "<< Same as input directory >>"){
				  // Proces each file seperate if output directory is specified
				  for(i=0; i<numberOfFiles; i++){
						  fileTemp = "" + lstFiles->Items[i];
						  fileTemp = txtOutputDirectory->Text + "\\" + fileTemp->Substring(fileTemp->LastIndexOf("\\"));
						  fileTemp = fileTemp->Substring(0,fileTemp->LastIndexOf(".")) + ".wav";
						  batch->WriteLine(command + "-o " + "\"" + fileTemp + "\" \"" + lstFiles->Items[i] + "\"");
					  }
			  } else {
				  // Proces in batches of 50 if file is processed in same directory
				  for(i=0; i<numberOfFiles; i++){
					  if (i % 50 == 0){
						  batch->WriteLine(tmpBatch);
						  tmpBatch = command;
					  }
					  tmpBatch += "\"" + lstFiles->Items[i] + "\" ";
				  }
				  batch->WriteLine(tmpBatch);
			  }

			 // Add pause to let console window stay 
			 batch->WriteLine("PAUSE");
			 // Close file, otherwise it won't execute
			 batch->Close();

			 // Execute batch-file
			 Process::Start(batchFileName);
		 }

private: System::Void btnTest_Click(System::Object^  sender, System::EventArgs^  e) {
			 // Let's first create some kind of BAT-file
			 String ^ batchFileName = Path::GetTempPath() + "flacfrontend.bat";
			 StreamWriter ^ batch = gcnew StreamWriter(batchFileName);
			 String ^ tmpBatch = "";
			 String ^ command = "flac.exe -t ";
			 int numberOfFiles = lstFiles->Items->Count;
			 int i;

			 // Supress commands and set codepage to unicode
			 batch->WriteLine("@ECHO OFF");
			 batch->WriteLine("chcp 65001");

			 if(chkDecodeThroughErrors->Checked == true)	command += "-F ";
			 
			 // Process in batches of 50
			 for(i=0; i<numberOfFiles; i++){
				 if (i % 50 == 0){
					batch->WriteLine(tmpBatch);
					tmpBatch = command;
				 }
				 tmpBatch += "\"" + lstFiles->Items[i] + "\" ";
			 }
			 batch->WriteLine(tmpBatch);
			 // Add pause to let console window stay 
			 batch->WriteLine("PAUSE");
			 // Close file, otherwise it won't execute
			 batch->Close();

			 // Execute batch-file
			 Process::Start(batchFileName);
		 }

private: System::Void btnFingerprint_Click(System::Object^  sender, System::EventArgs^  e) {
			 // Let's first create some kind of BAT-file
			 String ^ batchFileName = Path::GetTempPath() + "flacfrontend.bat";
			 StreamWriter ^ batch = gcnew StreamWriter(batchFileName);
			 String ^ tmpBatch = "";
			 String ^ command = "metaflac.exe --show-md5sum ";
			 int numberOfFiles = lstFiles->Items->Count;
			 int i;

			 // Supress commands and set codepage to unicode
			 batch->WriteLine("@ECHO OFF");
			 batch->WriteLine("chcp 65001");
			 
			 // Proces files in batches of 50
			 for(i=0; i<numberOfFiles; i++){
				 if (i % 50 == 0){
					batch->WriteLine(tmpBatch);
					tmpBatch = command;
				 }
				 tmpBatch += "\"" + lstFiles->Items[i] + "\" ";
			 }
			 batch->WriteLine(tmpBatch);
			 // Add pause to let console window stay 
			 batch->WriteLine("PAUSE");
			 // Close file, otherwise it won't execute
			 batch->Close();

			 // Execute batch-file
			 Process::Start(batchFileName);
		 }

private: System::Void btnExit_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }

// ---------------------------//
// --- Drag and drop stuff --- //
// ---------------------------//

private: System::Void lstFiles_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {
			 // Show user that dragdrop is possible
			 if(e->Data->GetDataPresent(DataFormats::FileDrop))
				 e->Effect = DragDropEffects::Link;
			 else
				 e->Effect = DragDropEffects::None;
		 }
private: System::Void lstFiles_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {
			 // Get filedrop into array of strings
			 array<String^>^ FileDropList = (array<String^>^)e->Data->GetData(DataFormats::FileDrop);
			 String^ FileDropItem = "";
			 String^ FileDropDirItem = "";
			 String^ extension = "";

			 // First process each item that has been dropped
			 for each (String^ FileDropItem in FileDropList){
				 if(Directory::Exists(FileDropItem)){
					 // Check whether dropped item is directory and find all files in that directory
					 for each (String^ FileDropDirItem in Directory::EnumerateFiles(FileDropItem,"*.*",SearchOption::AllDirectories)){			
						extension = FileDropDirItem->Substring(FileDropDirItem->LastIndexOf(".")+1);
						if((extension == "flac") || (extension == "oga") || (extension == "ogg") || (extension == "wav")){
							// In directory search, only add relevant files
							lstFiles->Items->Add(FileDropDirItem);
						}
					}
				} else {
					// If not a directory, just add the dropped item
					lstFiles->Items->Add(FileDropItem);
				}
			 }
		 }
};
}

