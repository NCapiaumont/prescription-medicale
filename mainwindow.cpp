#include "mainwindow.h"
#include "ui_mainwindow.h"
//INCLUDE EN PLUS *******************
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <QString>
#include <QTextCodec>
//FIN INCLUDE EN PLUS **************
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ouvreBase();
    this->chargeListePatient();
    this->chargeListeMedecin();
    this->chargeListeParametre();
    this->chargerListePrescription();
    this->chargeInfoPrescription();
    this->chargePrescriptionsARenouveler();
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
/////// GESTION DE LA BASE ////////////
//ferme la base
void MainWindow::fermeBase()
{
    this->base.close();
}
//ouvre la base
void MainWindow::ouvreBase()
{
    base=QSqlDatabase::addDatabase("QSQLITE");
    //nom fichier qui contient la base sqlite3
    base.setDatabaseName("gestionMedical.db");
    //ouverture de la base de données
    base.open();
    //si la base ne s'est pas ouverte correctement
    if(base.isOpen() != true){
            QMessageBox::critical(this, "Erreur critique", "Impossible d'ouvrir la base de données.");
        }else{
            this->verifBase();
    }
}
//vérifie l'erreur sur la table patient
void MainWindow::verifBase()
{
    //test si la base marche bien
    this->base.exec("select patNum, patNom, patNumSS, patDoc from patient;");
    this->base.exec("select docNum, patNom, docNumSS, docAdresse1, docAdresse2, docCP,docVille, docTel from medecin;");
    this->base.exec("select presNum, presDuree, presDateFin, presModeRenouv, presType, patNum from prescription;");
    this->base.exec("select paramCP, paramVille, paramDurDSI, paramDurOrdo, paramTempsOrdo from parametre;");
    if (this->base.lastError().isValid())//si la requete renvoie une erreur
    {
        qDebug()<<"Création des tables ...";
        this->creationDeLaBase();
    }
}
//creation des tables dans la base ainsi que la mise en place du jeu d'essai
void MainWindow::creationDeLaBase()
{
    this->base.exec("create table medecin(docNum int primary key,docNom varchar(30),docNumSS varchar(9),docAdresse1 varchar(100),docAdresse2 varchar(100),docCP varchar(5),docVille varchar(30),docTel varchar(10));");
    this->base.exec("create table patient(patNum int primary key,patNom varchar(30),patNumSS varchar(15),patDoc int,FOREIGN KEY (patDoc) REFERENCES medecin(docNum));");
            // presModeRenouv1 correspond a Patient this->saisieOKModif()ou Médecin (P/M)
            // presDuree en mois
            // presType correspond a DSI ou ordonnance (D/O)
    this->base.exec("create table prescription(presNum int primary key,presDuree tinyint,presDateFin text,presModeRenouv char(1),presType char(1),patNum int,FOREIGN KEY (patNum) REFERENCES patient(patNum));");
    this->base.exec("create table parametre(paramId smallint primary key,paramCP varchar(5),paramVille varchar(30),paramDurDSI tinyint,paramDurOrdo tinyint, paramTempsOrdo int);");
    //JEU D'ESSAI
    //A REUTILISER POUR UNE REINITIALISATION POSSIBLE DU LOGICIEL
    //ajout de medecins dans la base
    this->base.exec("insert into medecin values('1','Legrand','01234ABCD','6','Bd Pompidou','05000','gap','0454256841');");
    this->base.exec("insert into medecin values('2','Capiaumont','13410AZER','6 rue du serre de laure','residence les sorillions','05000','gap','0665773423');");
    //ajout de patient dans la base
    this->base.exec("insert into patient values ('1','Da Rocha','AZERTYUIO','2');");
    this->base.exec("insert into patient values ('2','Leleu','QSDFGHJKL','1');");
    this->base.exec("insert into patient values ('3','Rochas','WXCVBNJKL','1');");
    //ajout de prescriptions dans la base
    this->base.exec("insert into prescription values ('1','2','2013-9-12','P','O','1');");
    this->base.exec("insert into prescription values ('2','1','2013-11-30','M','D','2');");
    this->base.exec("insert into prescription values ('3','1','2013-10-09','M','O','3');");
    //ajout de parametre dans la base
    this->base.exec("insert into parametre values ('0','05000','GAP','3','2','15');");
}
/////////FIN GESTION BASE//////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

bool MainWindow::modificationParametre()
{
    return (ui->lineEditParametresCPMedecin->text().trimmed().length()*
            ui->lineEditParametreVilleMedecin->text().trimmed().length());
}
bool MainWindow::saisiePatientOK()
{
    return ( ui->lineEditPatientNom->text().trimmed().length());
             //*ui->lineEditPatientNumSS->text().trimmed().length());
}
//permet au bouton abandonner de s'activer quand au moins un champs est rempli (et de se désactiver dans le cas contraire)
bool MainWindow::saisiePatientOKAbandonner()
{
    return ((ui->lineEditPatientNom->text().trimmed().length())||(ui->lineEditPatientNumSS->text().trimmed().length()));
}
void MainWindow::on_pushButtonPatientAjouter_clicked()
{
    //renvoi le patNum maximum pour pouvoir faire un +1
    QSqlQuery req;
    req.exec("select max(patNum)+1 from patient;");
    req.first();
    this->base.exec("insert into patient values ("+req.value(0).toString()+",'"+ui->lineEditPatientNom->text().trimmed()+"','"+ui->lineEditPatientNumSS->text().trimmed()+"','"+QString::number(vectorIdPatientMedecin.value(ui->comboBoxPatientMedecin->currentIndex()))+"');");
    this->chargeListePatient();
}
void MainWindow::on_pushButtonPatientModifier_clicked()
{
    this->base.exec("update patient set patNom='"+ui->lineEditPatientNom->text().trimmed()+"', patNumSS='"+ui->lineEditPatientNumSS->text().trimmed()+"', patDoc='"+QString::number(vectorIdPatientMedecin.value(ui->comboBoxPatientMedecin->currentIndex()))+"' where patNum="+QString::number(this->vectorIdPatient.value(ui->listWidgetPatients->currentRow()))+";");
    this->chargeListePatient();
}
//vide tout les champs pour abandonner
void MainWindow::on_pushButtonPatientAbandonner_clicked()
{
    this->chargeListePatient();
}
//Supprime le patient selectionné
void MainWindow::on_pushButtonPatientSupprimer_clicked()
{
    this->base.exec("delete from patient where patNum="+QString::number(this->vectorIdPatient.value(ui->listWidgetPatients->currentIndex().row()))+";");
    this->chargeListePatient();
}
//charge la liste des patients
void MainWindow::chargeListePatient()
{
    //vidage de la listes des patients
    ui->listWidgetPatients->clear();
    this->vectorIdPatient.clear();
    /**************************************/
    /** chargement de la liste ************/
    /**************************************/
    //requete
    QSqlQuery req;
    //selectionne tous les patients par ordre alphabétique
    if (req.exec("select * from patient order by patNom;"))
    {
        while(req.next())
        {
               ui->listWidgetPatients->addItem(req.value(1).toString()+" - "+req.value(2).toString());
               this->vectorIdPatient.push_back(req.value(0).toInt());
        }
    }
    //initialisation des zones de saisie
    this->chargeListePatientMedecin();
    ui->lineEditPatientNom->clear();
    ui->lineEditPatientNumSS->clear();
    ui->pushButtonPatientAjouter->setEnabled(false);
    ui->pushButtonPatientModifier->setEnabled(false);
    ui->pushButtonPatientSupprimer->setEnabled(false);
    ui->pushButtonPatientAbandonner->setEnabled(false);
}
void MainWindow::chargeListePatientMedecin()
{
    ui->comboBoxPatientMedecin->clear();
    this->vectorIdPatientMedecin.clear();
    QSqlQuery req;
    ui->comboBoxPatientMedecin->addItem("Selectionnez un medecin...");
    this->vectorIdPatientMedecin.push_back(-1);
    //selectionne tous les docteurs par ordre alphabétique
    req=this->base.exec("select docNum, docNom from medecin order by docNom;");
    while(req.next())
        {
               //rempli les docteurs dans les patients
               ui->comboBoxPatientMedecin->addItem(req.value(1).toString());
               this->vectorIdPatientMedecin.push_back(req.value(0).toInt());
        }
}
//rempli les zones de saisies quand on clique sur un nom de patient
void MainWindow::on_listWidgetPatients_clicked(QModelIndex index)
{
        QSqlQuery res=this->base.exec("select patNom, patNumSS, docNum from patient inner join medecin on patDoc=docNum where patNum="+QString::number(this->vectorIdPatient.value(ui->listWidgetPatients->currentRow()))+";");
        if (res.first())
        {
        //affichage dans l'interface
        ui->lineEditPatientNom->setText(res.value(0).toString());
        ui->lineEditPatientNumSS->setText(res.value(1).toString());
        ui->comboBoxPatientMedecin->setCurrentIndex(this->vectorIdPatientMedecin.lastIndexOf(res.value(2).toInt()));
        ui->pushButtonPatientSupprimer->setEnabled(true);
        ui->pushButtonPatientModifier->setEnabled(false);
        ui->pushButtonPatientAbandonner->setEnabled(true);
        ui->pushButtonPatientAjouter->setEnabled(true);
    }
}
//GESTION DU BOUTON ABANDONNER/AJOUTER/MODIFIER
void MainWindow::on_comboBoxPatientMedecin_activated(QString )
{
    //permet d'abandonner quand on choisi un médecin dans la liste
    ui->pushButtonPatientAbandonner->setEnabled(this->saisiePatientOKAbandonner());
    //premet d'activer le bouton ajouter
    ui->pushButtonPatientAjouter->setEnabled(this->saisiePatientOK());
}
void MainWindow::on_lineEditPatientNumSS_textChanged(QString )
{
    //permet d'abandonner quand on rempli le patientNum
    ui->pushButtonPatientAbandonner->setEnabled(this->saisiePatientOKAbandonner());
    //premet d'activer le bouton ajouter
    ui->pushButtonPatientAjouter->setEnabled(this->saisiePatientOK());
    ui->pushButtonPatientModifier->setEnabled(this->saisiePatientOK());
}
void MainWindow::on_lineEditPatientNom_textChanged(QString )
{
    //permet d'abandonner quand on rempli le patientNom
    ui->pushButtonPatientAbandonner->setEnabled(this->saisiePatientOKAbandonner());
    //premet d'activer le bouton ajouter
    ui->pushButtonPatientAjouter->setEnabled(this->saisiePatientOK());
    ui->pushButtonPatientModifier->setEnabled(this->saisiePatientOK());
}
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////// MEDECIN ///////////////////////////////////////////
//charge la liste des medecins
void MainWindow::chargeListeMedecin()
{
    //vidage de la listes des medecins
    ui->listWidgetMedecins->clear();
    this->vectorIdMedecin.clear();
    /**************************************/
    /** chargement de la liste ************/
    /**************************************/
    //requete
    QSqlQuery req;
    //selectionne tous les medecins par ordre alphabétique
    if (req.exec("select * from medecin order by docNom;"))
    {
        while(req.next())
        {
               ui->listWidgetMedecins->addItem(req.value(1).toString());
               this->vectorIdMedecin.push_back(req.value(0).toInt());
        }
    }
    //rempli avec les parametres par defauts
    QSqlQuery res;
    if(res.exec("select * from parametre;"))
    {
        while(res.next())
        {
            ui->lineEditMedecinCP->setText(res.value(1).toString());
            ui->lineEditMedecinVille->setText(res.value(2).toString());
        }
    }
    //initialisation des zones de saisie
    ui->lineEditMedecinAdr1->clear();
    ui->lineEditMedecinAdr2->clear();
    //ui->lineEditMedecinCP->clear();
    ui->lineEditMedecinNom->clear();
    ui->lineEditMedecinNumSS->clear();
    ui->lineEditMedecinTel->clear();
    //ui->lineEditMedecinVille->clear();
    ui->pushButtonPatientAjouter->setEnabled(false);
    ui->pushButtonPatientModifier->setEnabled(false);
    ui->pushButtonPatientSupprimer->setEnabled(false);
    ui->pushButtonPatientAbandonner->setEnabled(false);
}
void MainWindow::on_listWidgetMedecins_clicked(QModelIndex index)
{
    QSqlQuery res=this->base.exec("select docNum, docNom, docNumSS, docAdresse1, docAdresse2,docCP,docVille,docTel from medecin where docNum="+QString::number(this->vectorIdMedecin.value(ui->listWidgetMedecins->currentRow()))+";");
    if (res.first())
    {
    //affichage dans l'interface
    ui->lineEditMedecinNom->setText(res.value(1).toString());
    ui->lineEditMedecinNumSS->setText(res.value(2).toString());
    ui->lineEditMedecinAdr1->setText(res.value(3).toString());
    ui->lineEditMedecinAdr2->setText(res.value(4).toString());
    ui->lineEditMedecinCP->setText(res.value(5).toString());
    ui->lineEditMedecinVille->setText(res.value(6).toString());
    ui->lineEditMedecinTel->setText(res.value(7).toString());
    ui->comboBoxPatientMedecin->setCurrentIndex(this->vectorIdPatientMedecin.lastIndexOf(res.value(2).toInt()));
    ui->pushButtonMedecinAbandonner->setEnabled(true);
    ui->pushButtonMedecinModifier->setEnabled(false);
    ui->pushButtonMedecinAjouter->setEnabled(true);
    ui->pushButtonMedecinSupprimer->setEnabled(true);
    }
}

void MainWindow::on_pushButtonMedecinAbandonner_clicked()
{
    this->chargeListeMedecin();
}
void MainWindow::on_pushButtonMedecinSupprimer_clicked()
{
    this->base.exec("delete from medecin where docNum="+QString::number(this->vectorIdMedecin.value(ui->listWidgetMedecins->currentIndex().row()))+";");
    this->chargeListeMedecin();
}
void MainWindow::on_pushButtonMedecinModifier_clicked()
{
    this->base.exec("update medecin set docNom='"+ui->lineEditMedecinNom->text().trimmed()+
                    "',docNumSS='"+ui->lineEditMedecinNumSS->text().trimmed()+
                    "',docAdresse1='"+ui->lineEditMedecinAdr1->text().trimmed()+
                    "',docAdresse2='"+ui->lineEditMedecinAdr2->text().trimmed()+
                    "',docCP='"+ui->lineEditMedecinCP->text().trimmed()+
                    "',docVille='"+ui->lineEditMedecinVille->text().trimmed()+
                    "',docTel='"+ui->lineEditMedecinTel->text().trimmed()+
                    "' where docNum="+QString::number(this->vectorIdMedecin.value(ui->listWidgetMedecins->currentRow()))+";");
    this->chargeListeMedecin();
}
void MainWindow::on_pushButtonMedecinAjouter_clicked()
{
    //renvoi le medNum maximum pour pouvoir faire un +1
    QSqlQuery req;
    req.exec("select max(docNum)+1 from medecin;");
    req.first();
    this->base.exec("insert into medecin values ("+req.value(0).toString()+
                    ",'"+ui->lineEditMedecinNom->text().trimmed()+
                    "','"+ui->lineEditMedecinNumSS->text().trimmed()+
                    "','"+ui->lineEditMedecinAdr1->text().trimmed()+
                    "','"+ui->lineEditMedecinAdr2->text().trimmed()+
                    "','"+ui->lineEditMedecinCP->text().trimmed()+
                    "','"+ui->lineEditMedecinVille->text().trimmed()+
                    "','"+ui->lineEditMedecinTel->text().trimmed()+"')");
    this->chargeListeMedecin();
}
bool MainWindow::saisieMedecinOK()
{
    return ( ui->lineEditMedecinNom->text().trimmed().length()*
             ui->lineEditMedecinNumSS->text().trimmed().length());
             //ui->lineEditMedecinTel->text().trimmed().length()*
             //ui->lineEditMedecinVille->text().trimmed().length()*
             //ui->lineEditMedecinCP->text().trimmed().length()*
             //(ui->lineEditMedecinAdr1->text().trimmed().length()||ui->lineEditMedecinAdr2->text().trimmed().length()));
                 
}
bool MainWindow::saisieMedecinOKAbandonner()
{
    return ( ui->lineEditMedecinNom->text().trimmed().length()||
             ui->lineEditMedecinNumSS->text().trimmed().length()||
             ui->lineEditMedecinTel->text().trimmed().length()||
             ui->lineEditMedecinVille->text().trimmed().length()||
             ui->lineEditMedecinCP->text().trimmed().length()||
             ui->lineEditMedecinAdr1->text().trimmed().length()||
             ui->lineEditMedecinAdr2->text().trimmed().length());
}
void MainWindow::on_lineEditMedecinNom_textChanged(QString )
{
    ui->pushButtonMedecinAbandonner->setEnabled(this->saisieMedecinOKAbandonner());
    ui->pushButtonMedecinAjouter->setEnabled(this->saisieMedecinOK());
    ui->pushButtonMedecinModifier->setEnabled(this->saisieMedecinOK());
}
void MainWindow::on_lineEditMedecinNumSS_textChanged(QString )
{
    ui->pushButtonMedecinAbandonner->setEnabled(this->saisieMedecinOKAbandonner());
    ui->pushButtonMedecinAjouter->setEnabled(this->saisieMedecinOK());
    ui->pushButtonMedecinModifier->setEnabled(this->saisieMedecinOK());
}
void MainWindow::on_lineEditMedecinAdr1_textChanged(QString )
{    ui->pushButtonMedecinAbandonner->setEnabled(this->saisieMedecinOKAbandonner());
    ui->pushButtonMedecinAjouter->setEnabled(this->saisieMedecinOK());

    ui->pushButtonMedecinModifier->setEnabled(this->saisieMedecinOK());
}
void MainWindow::on_lineEditMedecinAdr2_textChanged(QString )
{
    ui->pushButtonMedecinAbandonner->setEnabled(this->saisieMedecinOKAbandonner());
    ui->pushButtonMedecinAjouter->setEnabled(this->saisieMedecinOK());
    ui->pushButtonMedecinModifier->setEnabled(this->saisieMedecinOK());
}
void MainWindow::on_lineEditMedecinCP_textChanged(QString )
{
    ui->pushButtonMedecinAbandonner->setEnabled(this->saisieMedecinOKAbandonner());
    ui->pushButtonMedecinAjouter->setEnabled(this->saisieMedecinOK());
    ui->pushButtonMedecinModifier->setEnabled(this->saisieMedecinOK());
}
void MainWindow::on_lineEditMedecinVille_textChanged(QString )
{
    ui->pushButtonMedecinAbandonner->setEnabled(this->saisieMedecinOKAbandonner());
    ui->pushButtonMedecinAjouter->setEnabled(this->saisieMedecinOK());
    ui->pushButtonMedecinModifier->setEnabled(this->saisieMedecinOK());
}
void MainWindow::on_lineEditMedecinTel_textChanged(QString )
{
    ui->pushButtonMedecinAbandonner->setEnabled(this->saisieMedecinOKAbandonner());
    ui->pushButtonMedecinAjouter->setEnabled(this->saisieMedecinOK());
    ui->pushButtonMedecinModifier->setEnabled(this->saisieMedecinOK());
}
void MainWindow::on_comboBoxPatientMedecin_currentIndexChanged(QString )
{
    ui->pushButtonPatientAbandonner->setEnabled(this->saisieMedecinOKAbandonner());
    ui->pushButtonPatientModifier->setEnabled(true);
    ui->pushButtonPatientAjouter->setEnabled(this->saisieMedecinOK());

}
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////// PARAMETRE /////////////////////////////////////////
//réinitialise toute la base a 0
void MainWindow::on_pushButtonReinitialiser_clicked()
{
    //supprime les tables de la base
    this->base.exec("drop table prescription;");
    this->base.exec("drop table patient;");
    this->base.exec("drop table medecin;");
    this->base.exec("drop table parametre");
    qDebug()<<"Création des tables ...";
    //creation des tables dans la base ainsi que la mise en place du jeu d'essai
    this->creationDeLaBase();
    this->chargeListeMedecin();
    this->chargeListePatient();
    this->chargerListePrescription();
    this->chargePrescriptionsARenouveler();
    this->chargeListeParametre();
    QMessageBox::critical(this, QString::fromUtf8("Réinitialisation"), QString::fromUtf8("Création de la base de donnée..."));
}
//charge parametre
void MainWindow::chargeListeParametre()
{
    //initialisation des zones de saisie
    ui->lineEditParametresCPMedecin->clear();
    ui->lineEditParametreVilleMedecin->clear();
    ui->spinBoxParametreDureeDSI->clear();
    ui->spinBoxPrescriptionDureeOdronnance->clear();
    ui->pushButtonPrescriptionEnregistrer->setEnabled(false);
    /**************************************/
    /** chargement de la liste ************/
    /**************************************/
    //requete
    QSqlQuery req;
    if (req.exec("select * from parametre;"))
    {
        while(req.next())
        {
            ui->lineEditParametresCPMedecin->setText(req.value(1).toString());
            ui->lineEditParametreVilleMedecin->setText(req.value(2).toString());
            ui->spinBoxPrescriptionDureeOdronnance->setValue(req.value(4).toInt());
            ui->spinBoxParametreDureeDSI->setValue(req.value(3).toInt());
            ui->spinBoxParametreARenouvelerTemps->setValue(req.value(5).toInt());
        }
    }
}
void MainWindow::on_pushButtonPrescriptionEnregistrer_clicked()
{
    this->base.exec("update parametre set paramCP='"+ui->lineEditParametresCPMedecin->text().trimmed()+
                    "',paramVille='"+ui->lineEditParametreVilleMedecin->text().trimmed()+
                    "',paramDurDSI='"+ui->spinBoxParametreDureeDSI->text()+
                    "',paramDurOrdo='"+ui->spinBoxPrescriptionDureeOdronnance->text()+
                    "',paramTempsOrdo='"+ui->spinBoxParametreARenouvelerTemps->text()+
                    "' where paramId=0;");
    this->chargeListeParametre();
    this->chargeListeMedecin();
    this->chargeListePatient();
    this->chargeListePatientMedecin();
    this->chargePrescriptionsARenouveler();
    this->chargerListePrescription();
}
void MainWindow::on_lineEditParametresCPMedecin_textChanged(QString )
{
    ui->pushButtonPrescriptionEnregistrer->setEnabled(this->modificationParametre());
}
void MainWindow::on_lineEditParametreVilleMedecin_textChanged(QString )
{
    ui->pushButtonPrescriptionEnregistrer->setEnabled(this->modificationParametre());
}
void MainWindow::on_spinBoxParametreDureeDSI_valueChanged(int )
{
    ui->pushButtonPrescriptionEnregistrer->setEnabled(this->modificationParametre());
}
void MainWindow::on_spinBoxPrescriptionDureeOdronnance_valueChanged(int )
{
    ui->pushButtonPrescriptionEnregistrer->setEnabled(this->modificationParametre());
}
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
void MainWindow::chargeInfoPrescription()
{
    //Affichage de la combo
    QSqlQuery req;
    req.exec("select patNum,patNom from patient");
    while(req.next())
    {
        ui->comboBoxPrescriptionPatient->addItem(req.value(1).toString());
        this->vectorPatNum.push_back(req.value(0).toInt());
    }
    //affichage de la date courante
    ui->dateEditPrescriptionDateDebut->setDate(QDate::currentDate());
    //mise a 0 de la spin box
    ui->spinBoxPrescriptionDuree->setValue(0);
    //On coche automatiquement
    ui->radioButtonOrdonnance->setChecked(true);
    ui->radioButtonPatient->setChecked(true);
    this->on_radioButtonOrdonnance_clicked();
}
void MainWindow::chargerListePrescription()
{
    //vidage de la liste des prescriptions
    ui->listWidgetPrescriptions->clear();
    this->vectorId.clear();
    /**************************************/
    /** chargement de la liste*************/
    /**************************************/
    //requete
    QString type;
    QSqlQuery req;
    if (req.exec("select * from prescription natural join patient;"))
    {
        while(req.next())
        {
            if(req.value(4).toString()=="O")
            {
                type="Ordonnance";
            }
            else if(req.value(4).toString()=="D")
            {
                type="DSI";
            }
            QDate date=QDate::fromString(req.value(2).toString(),"yyyy-MM-dd");
                ui->listWidgetPrescriptions->addItem(type+" de "+req.value(6).toString()+" fin le "+date.toString("dd/MM/yyyy"));
                this->vectorId.push_back(req.value(0).toInt());
        }
    }
    ui->pushButtonPrescriptionSupprimer->setEnabled(false);
    ui->pushButtonPrescriptionModifier->setEnabled(false);
    ui->pushButtonPrescriptionAbandonner->setEnabled(false);
    ui->pushButtonPrescriptionAjouter->setEnabled(false);
}
void MainWindow::on_listWidgetPrescriptions_clicked(QModelIndex index)
{
    QSqlQuery res=this->base.exec("select presDuree,patNum,presDateFin,presType,presModeRenouv from prescription where presNum="+QString::number(this->vectorId.value(ui->listWidgetPrescriptions->currentIndex().row()))+";");
    if (res.first())
    {
        //affichage dans l'interface
        ui->comboBoxPrescriptionPatient->setCurrentIndex(this->vectorPatNum.lastIndexOf(res.value(1).toInt()));
        ui->spinBoxPrescriptionDuree->setValue(res.value(0).toInt());
        if(res.value(3).toString()=="D")
        {
            ui->radioButtonDSI->setChecked(true);
        }
        else if(res.value(3).toString()=="O")
        {
            ui->radioButtonOrdonnance->setChecked(true);
        }
        if (res.value(4).toString()=="M")
        {
            ui->radioButtonMedecin->setChecked(true);
        }
        else if(res.value(4)=="P")
        {
            ui->radioButtonPatient->setChecked(true);
        }
        QDate dateFin=QDate::fromString(res.value(2).toString(),"yyyy-MM-dd");
        int duree=res.value(0).toInt();
        QDate dateDebut=dateFin.addMonths(-duree);
        ui->dateEditPrescriptionDateDebut->setDate(dateDebut);
        ui->pushButtonPrescriptionAbandonner->setEnabled(true);
        ui->pushButtonPrescriptionSupprimer->setEnabled(true);
        ui->pushButtonPrescriptionModifier->setEnabled(true);
    }
}
void MainWindow::on_pushButtonPrescriptionAjouter_clicked()
{
    QSqlQuery res=this->base.exec("select max(presNum) from prescription");
    if(res.first())
    {
        char type;
        char modeRenouvellement;
        if(ui->radioButtonMedecin->isChecked())
        {
            modeRenouvellement='M';
        }
        else if(ui->radioButtonPatient->isChecked())
        {
            modeRenouvellement='P';
        }
        if(ui->radioButtonDSI->isChecked())
        {
            type='D';
        }
        else if(ui->radioButtonOrdonnance->isChecked())
        {
            type='O';
        }
        QDate dateDebut=ui->dateEditPrescriptionDateDebut->date();
        int duree=ui->spinBoxPrescriptionDuree->value();
        QDate dateFin=dateDebut.addMonths(duree);
        int numPat=vectorPatNum.at(ui->comboBoxPrescriptionPatient->currentIndex());
        QSqlQuery res2="Insert into prescription values("+QString::number(res.value(0).toInt()+1)+","+QString::number(ui->spinBoxPrescriptionDuree->value())+",'"+dateFin.toString("yyyy-MM-dd")+"','"+modeRenouvellement+"','"+type+"',"+QString::number(numPat)+")";
        res2.first();
        this->chargerListePrescription();
        this->chargePrescriptionsARenouveler();
    }
}
void MainWindow::on_pushButtonPrescriptionModifier_clicked()
{
    QSqlQuery res=this->base.exec("select presNum from prescription where presNum="+QString::number(this->vectorId.value(ui->listWidgetPrescriptions->currentIndex().row()))+";");
    if(res.first())
    {
        char type;
        char modeRenouvellement;
        if(ui->radioButtonMedecin->isChecked())
        {
            modeRenouvellement='M';
        }
        else if(ui->radioButtonPatient->isChecked())
        {
            modeRenouvellement='P';
        }
        if(ui->radioButtonDSI->isChecked())
        {
            type='D';
        }
        else if(ui->radioButtonOrdonnance->isChecked())
        {
            type='O';
        }
        QDate dateDebut=ui->dateEditPrescriptionDateDebut->date();
        int duree=ui->spinBoxPrescriptionDuree->value();
        QDate dateFin=dateDebut.addMonths(duree);
        int numPat=vectorPatNum.at(ui->comboBoxPrescriptionPatient->currentIndex());
        QSqlQuery res2="update prescription set presDuree="+QString::number(duree)+",presDateFin='"+dateFin.toString("yyyy-MM-dd")+"',presModeRenouv='"+modeRenouvellement+"',presType='"+type+"',patNum="+QString::number(numPat)+" where presNum="+res.value(0).toString()+";";
        res2.first();
        this->chargerListePrescription();
        this->chargePrescriptionsARenouveler();
    }
}
void MainWindow::on_pushButtonPrescriptionAbandonner_clicked()
{
        ui->spinBoxPrescriptionDuree->setValue(0);
        this->chargerListePrescription();
        ui->dateEditPrescriptionDateDebut->setDate(QDate::currentDate());
        ui->radioButtonOrdonnance->setChecked(true);
        ui->radioButtonPatient->setChecked(true);
        this->on_radioButtonOrdonnance_clicked();
}
void MainWindow::on_pushButtonPrescriptionSupprimer_clicked()
{
    QSqlQuery res=this->base.exec("select presNum from prescription where presNum="+QString::number(this->vectorId.value(ui->listWidgetPrescriptions->currentIndex().row()))+";");
    if(res.first())
    {
        int presNum=res.value(0).toInt();
        QSqlQuery res2=this->base.exec("delete from prescription where presNum="+QString::number(presNum)+";");
        res2.first();
        this->chargerListePrescription();
        this->chargePrescriptionsARenouveler();
    }
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//charge la liste des prescriptions
void MainWindow::chargePrescriptionsARenouveler()
{
    //vidage de la listes des Prescriptions A Renouveler
    ui->listWidgetPrescriptionsARenouveler->clear();
    this->vectorIdPrescriptionARenouveler.clear();
    /**************************************/
    /** chargement de la liste ************/
    /**************************************/
    //requete
    QSqlQuery req;
    //selectionne toute les prescriptions a renouveler
    if (req.exec("select patNom,presDateFin,presNum from prescription natural join patient where date('now','"+QString::number(ui->spinBoxParametreARenouvelerTemps->value())+" day')>=presDateFin order by presDateFin desc;"))
    {
        while(req.next())
        {
            QDate date=QDate::fromString(req.value(1).toString(),"yyyy-MM-dd");
               ui->listWidgetPrescriptionsARenouveler->addItem(req.value(0).toString()+" "+date.toString("dd/MM/yyyy"));
               this->vectorIdPrescriptionARenouveler.push_back(req.value(2).toInt());
        }
    }
    //vidage des zones de saisie
    ui->labelARenouvelerPatient->clear();
    ui->labelARenouvelerMedAd1->clear();
    ui->labelARenouvelerMedAd2->clear();
    ui->labelARenouvelerMedCPVille->clear();
    ui->labelARenouvelerMedNumNom->clear();
    ui->labelARenouvelerMedTel->clear();
    ui->labelARenouvelerPresDateFin->clear();
    ui->labelARenouvelerPresDuree->clear();
    ui->labelARenouvelerPresModeR->clear();
    ui->labelARenouvelerPresType->clear();
}
void MainWindow::on_listWidgetPrescriptionsARenouveler_clicked(QModelIndex index)
{
    //tout part de là
    QString type;
    QString modeRenouv;
    QSqlQuery res=this->base.exec("select * from prescription natural join patient inner join medecin on patDoc=docNum where presNum="+QString::number(this->vectorIdPrescriptionARenouveler.value(ui->listWidgetPrescriptionsARenouveler->currentIndex().row()))+" ;");
    //si la prescription a bien été trouvé
    if (res.first())
    {
        if(res.value(4).toString()=="O")
        {
            type="Ordonnance";
        }
        else if(res.value(4).toString()=="D")
        {
            type="DSI";
        }

        if(res.value(3).toString()=="P")
        {
            modeRenouv="Patient";
        }
        else if(res.value(3).toString()=="M")
        {
            modeRenouv="Médecin";
        }
        //affichage dans l'interface (info patient)
        ui->labelARenouvelerPatient->setText(res.value(6).toString());
        //affichage dans l'interface (info prescription)
        QDate date=QDate::fromString(res.value(2).toString(),"yyyy-MM-dd");
        ui->labelARenouvelerPresDateFin->setText(date.toString("dd/MM/yyyy"));
        ui->labelARenouvelerPresDuree->setText(res.value(1).toString());
        ui->labelARenouvelerPresType->setText(type);
        ui->labelARenouvelerPresModeR->setText(modeRenouv);
        //affichage dans l'interface (info medecin)
        ui->labelARenouvelerMedAd1->setText(res.value(12).toString());
        ui->labelARenouvelerMedAd2->setText(res.value(13).toString());
        ui->labelARenouvelerMedCPVille->setText(res.value(14).toString()+" "+res.value(15).toString());
        ui->labelARenouvelerMedTel->setText(res.value(16).toString());
        ui->labelARenouvelerMedNumNom->setText(res.value(10).toString());

        //activation des de la date et du bouton
        ui->dateEditARenouvelerPresDateFin->setEnabled(true);
        ui->pushButtonARenouvelerRenouveler->setEnabled(true);

        //mise en place de la bonne date dans la dateEdit
        ui->dateEditARenouvelerPresDateFin->setMinimumDate(QDate::currentDate().addDays(1));
        QDate maDate=QDate::fromString(res.value(2).toString(),"yyyy-MM-dd");
        maDate=maDate.addMonths(res.value(1).toInt());
        ui->dateEditARenouvelerPresDateFin->setDate(maDate);
    }
}
void MainWindow::on_radioButtonOrdonnance_clicked()
{
    QSqlQuery res=this->base.exec("Select paramDurOrdo from parametre");
    res.first();
    ui->spinBoxPrescriptionDuree->setValue(res.value(0).toInt());
}
void MainWindow::on_radioButtonDSI_clicked()
{
    QSqlQuery res=this->base.exec("Select paramDurDSI from parametre");
    res.first();
    ui->spinBoxPrescriptionDuree->setValue(res.value(0).toInt());
}
void MainWindow::on_pushButtonARenouvelerRenouveler_clicked()
{
    //requete pour renouveler à faire
    QSqlQuery res=this->base.exec("update prescription set presDateFin='"+ui->dateEditARenouvelerPresDateFin->date().toString("yyyy-MM-dd")+"' where presNum="+QString::number(this->vectorIdPrescriptionARenouveler.value(ui->listWidgetPrescriptionsARenouveler->currentIndex().row()))+";");
    qDebug()<<"update prescription set presDateFin='"+ui->dateEditARenouvelerPresDateFin->date().toString("dd/MM/yyyy")+"' where presNum="+QString::number(this->vectorIdPrescriptionARenouveler.value(ui->listWidgetPrescriptionsARenouveler->currentIndex().row()))+";";
    this->chargePrescriptionsARenouveler();
    this->chargerListePrescription();
}

void MainWindow::on_comboBoxPrescriptionPatient_activated(QString )
{
    ui->pushButtonPrescriptionAjouter->setEnabled(true);
}
