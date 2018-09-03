#ifndef STARTCHANNELDIALOG_H
#define STARTCHANNELDIALOG_H

//(*Headers(StartChannelDialog)
#include <wx/choice.h>
#include <wx/dialog.h>
#include <wx/radiobut.h>
#include <wx/sizer.h>
#include <wx/spinctrl.h>
#include <wx/stattext.h>
//*)

#include <string>
class ModelManager;
class OutputManager;

class StartChannelDialog: public wxDialog
{
	public:

		StartChannelDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~StartChannelDialog();

		//(*Declarations(StartChannelDialog)
		wxChoice* ChoiceController;
		wxChoice* ModelChoice;
		wxChoice* OutputChoice;
		wxChoice* ipChoice;
		wxChoice* universeChoice;
		wxRadioButton* ModelButton;
		wxRadioButton* NoneButton;
		wxRadioButton* OutputButton;
		wxRadioButton* RadioButton1;
		wxRadioButton* StartModelButton;
		wxRadioButton* UniverseButton;
		wxSpinCtrl* StartChannel;
		//*)
    
        void Set(const wxString &start, const ModelManager &models);
        void SetUniverseOptionsBasedOnIP(wxString ip);
        std::string Get();
        OutputManager* _outputManager;

	protected:

		//(*Identifiers(StartChannelDialog)
		static const long ID_SPINCTRL1;
		static const long ID_RADIOBUTTON1;
		static const long ID_RADIOBUTTON2;
		static const long ID_CHOICE2;
		static const long ID_RADIOBUTTON5;
		static const long ID_CHOICE3;
		static const long ID_CHOICE4;
		static const long ID_RADIOBUTTON3;
		static const long ID_CHOICE1;
		static const long ID_RADIOBUTTON4;
		static const long ID_RADIOBUTTON6;
		static const long ID_CHOICE5;
		//*)

	private:

		//(*Handlers(StartChannelDialog)
		void OnButtonSelect(wxCommandEvent& event);
		void OnipChoiceSelect(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
