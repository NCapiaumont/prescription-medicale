#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QModelIndex>
#include <QListWidgetItem>
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void chargeListePatient();
    void chargeListePatientMedecin();
    void fermeBase();
    void ouvreBase();
    void verifBase();
    bool saisiePatientOK();//vérifie si la saisie ets OK pour activer les boutons
    bool saisiePatientOKAbandonner();//vérifie qu'il y ai au moins un champs de rempli pour pouvoir abandonner
    void chargeListeMedecin();
    bool saisieMedecinOK();
    bool saisieMedecinOKAbandonner();//vérifie qu'il y ai au moins un champs de rempli pour pouvoir abandonner
    void chargeListeParametre();
    bool modificationParametre();
    void chargerListePrescription();
    QVector<int> vectorId;
    QVector<int> vectorPatNum;
    void chargeInfoPrescription();
    void chargePrescriptionsARenouveler();
    void creationDeLaBase();




protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    QVector<int> vectorIdPatient, vectorIdPatientMedecin, vectorIdMedecin;
    QSqlDatabase base;
    QVector<int> vectorIdPrescriptionARenouveler;

private slots:
    void on_pushButtonARenouvelerRenouveler_clicked();
    void on_radioButtonDSI_clicked();
    void on_radioButtonOrdonnance_clicked();
    void on_listWidgetPrescriptionsARenouveler_clicked(QModelIndex index);
    void on_spinBoxPrescriptionDureeOdronnance_valueChanged(int );
    void on_spinBoxParametreDureeDSI_valueChanged(int );
    void on_lineEditParametreVilleMedecin_textChanged(QString );
    void on_lineEditParametresCPMedecin_textChanged(QString );
    void on_pushButtonPrescriptionEnregistrer_clicked();
    void on_comboBoxPatientMedecin_currentIndexChanged(QString );
    void on_pushButtonReinitialiser_clicked();
    void on_lineEditMedecinTel_textChanged(QString );
    void on_lineEditMedecinVille_textChanged(QString );
    void on_lineEditMedecinCP_textChanged(QString );
    void on_lineEditMedecinAdr2_textChanged(QString );
    void on_lineEditMedecinAdr1_textChanged(QString );
    void on_lineEditMedecinNumSS_textChanged(QString );
    void on_lineEditMedecinNom_textChanged(QString );
    void on_pushButtonMedecinAjouter_clicked();
    void on_pushButtonMedecinModifier_clicked();
    void on_pushButtonMedecinSupprimer_clicked();
    void on_pushButtonMedecinAbandonner_clicked();
    void on_listWidgetMedecins_clicked(QModelIndex index);
    void on_lineEditPatientNom_textChanged(QString );
    void on_lineEditPatientNumSS_textChanged(QString );
    void on_comboBoxPatientMedecin_activated(QString );
    void on_listWidgetPatients_clicked(QModelIndex index);
    void on_pushButtonPatientSupprimer_clicked();
    void on_pushButtonPatientAbandonner_clicked();
    void on_pushButtonPatientModifier_clicked();
    void on_pushButtonPatientAjouter_clicked();
    void on_comboBoxPrescriptionPatient_activated(QString );
    void on_pushButtonPrescriptionSupprimer_clicked();
    void on_pushButtonPrescriptionAbandonner_clicked();
    void on_pushButtonPrescriptionModifier_clicked();
    void on_pushButtonPrescriptionAjouter_clicked();
    void on_listWidgetPrescriptions_clicked(QModelIndex index);
};
#endif // MAINWINDOW_H
