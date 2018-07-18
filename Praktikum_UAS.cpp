#include "iostream"
#include "conio.h"
#include "windows.h"
#include <fstream>
using namespace std;

int header=0;
typedef struct Emergency_Contact{
    char namakontak_darurat[50];
    char alamat_darurat[50];
    long long int nohp_darurat;
    char hubungan_darurat[50];
};

typedef struct Data_Company{
    char nama_perusahaan[50];
    char tinggal_perusahaan[50];
    long long int nohp_perusahaan;
    char posisi_perusahaan[50];
    char divisi_perusahaan[50];
};

typedef struct Data_Applicant{
    long long int noktp;
    char nama_app[50];
    char address[50];
    long long int nohp;
    char email[50];
    char lama_kerja[50];
    char status_tinggal[50];
};

typedef struct Tenor{
    long long int jmlh_pinjam;
    long long int norek;
    long long int masa_pinjam;
};

typedef struct Application_form {
    int kode;
    long long int tenor;
    char nama[50];
    char time[50];
    char scan_ktp[50];
    char scan_npwp[50];
    char scan_slip[50];
    Data_Applicant data;
    Data_Company perusahaan;
    Emergency_Contact darurat;
    Tenor pinjam;
};

Application_form form[20];

typedef struct {
	int base[100];
	char base1[100][20];
	int depan;
	int belakang;
}queue;
queue antrian;
queue nama;

char base1[20];
int base, i, j;

int isEmpty () {
	if (antrian.belakang == -1)
 	return 1;
 	else
 	return 0;
}

int isFull () {
	if (antrian.belakang == 100)
 	return 1;
 	else
 	return 0;
}

 void report(int p){
 	ofstream report;
 	report.open("keren.txt",ios_base::app);
 	report<< "\t\t|Data ke-"<<(p+1)<<endl;
	report<< "\t\t|Formulir Pinjaman                               "<<endl;
	report<< "\t\t|\tKode_Peminjaman         : " << form[p].kode << endl;
	report<< "\t\t|\tLoad_Tenor              : " << form[p].tenor << endl;
	report<< "\t\t|\tNama Sales              : " << form[p].nama << endl;
	report<< "\t\t|\tTanggal dan waktu       : " << form[p].time << endl;
	report<< "\t\t|\tScan ID Number KTP      : " << form[p].scan_ktp << endl;
	report<< "\t\t|\tScan Number NPWP        : " << form[p].scan_npwp << endl;
	report<< "\t\t|\tScan Salary Slip        : " <<form[p].scan_slip << endl;
	report<< "\t\t|                                               "<<endl;
	report<< "\t\t|Data Pemohon                                 "<<endl;
	report<< "\t\t|\tNo. KTP                  : " << form[p].data.noktp << endl;
	report<< "\t\t|\tNama Pemohon            : " << form[p].data.nama_app << endl;
	report<< "\t\t|\tAlamat saat ini         : " << form[p].data.address << endl;       	
	report<< "\t\t|\tNo HP                   : " << form[p].data.nohp << endl;
	report<< "\t\t|\tEmail                   : " << form[p].data.email << endl;
	report<< "\t\t|\tLama Berkeja            : " << form[p].data.lama_kerja << endl;
	report<< "\t\t|\tStatus Tempat Tinggal   : "<< form[p].data.status_tinggal <<endl;
	report<< "\t\t|                                               "<<endl;
	report<< "\t\t|Data Perusahaan                                   "<<endl;
	report<< "\t\t|\tNama Perusahaan         : " << form[p].perusahaan.nama_perusahaan << endl;
	report<< "\t\t|\tAlamat perusahaan       : " << form[p].perusahaan.tinggal_perusahaan << endl;
	report<< "\t\t|\tNo.Telp Perusahaan      : " << form[p].perusahaan.nohp_perusahaan << endl;
	report<< "\t\t|\tPosisi Pekerjaan        : " << form[p].perusahaan.posisi_perusahaan << endl;       	
	report<< "\t\t|\tDivisi kerja            : " << form[p].perusahaan.divisi_perusahaan << endl;
	report<< "\t\t|                                               "<<endl;
	report<< "\t\t|Kontak Darurat                              "<<endl;
	report<< "\t\t|\tNama Kontak             : " << form[p].darurat.namakontak_darurat <<endl;
	report<< "\t\t|\tAlamat Darurat          : " << form[p].darurat.alamat_darurat <<endl;
	report<< "\t\t|\tNo.HP Darurat           : " << form[p].darurat.nohp_darurat << endl;
	report<< "\t\t|\tHubungan Kontak Darurat : " << form[p].darurat.hubungan_darurat << endl;
	report<< "\t\t|                                               "<<endl;
	report<< "\t\t|Tenor                                          "<<endl;
	report<< "\t\t|\tJumlah Pinjaman         : " << form[p].pinjam.jmlh_pinjam << endl;       	
	report<< "\t\t|\tNo Rekening Transfer    : " << form[p].pinjam.norek << endl;
	report<< "\t\t|\tPanjang Pinjaman        : " << form[p].pinjam.masa_pinjam << endl;
	report<< "\t\t|                                               "<<endl;
 	report<<endl<<endl<<endl;

	report.close();
 }

void head(){
	cout << "\t\t|===============================================|"<<endl;
	cout << "\t\t|                                               |"<<endl;
	cout << "\t\t|          APLIKASI FINANCIAL BANKING           |"<<endl;
	cout << "\t\t|                   BANK XYZ                    |"<<endl;
	cout << "\t\t|                                               |"<<endl;
	cout << "\t\t|===============================================|"<<endl;
	cout << "\t\t|                                               |"<<endl;
}

 void edit(int z){
 	cout << "\t\t| ---Application Form---                        |"<<endl;
    cout << "\t\t| Kode_Peminjaman (max 5)    : "; cin >> form[z].kode;
    cout << "\t\t| Load_Tenor                 : "; cin >>form[z].tenor; cin.ignore();
    cout << "\t\t| Nama_Sales                 : "; cin.getline(form[z].nama,20);
    cout << "\t\t| Date_And_Time              : "; cin >>form[z].time; cin.ignore();
    cout << "\t\t| Scan ID Number KTP         : "; cin.getline(form[z].scan_ktp,20); //cin.ignore();
    cout << "\t\t| Scan Number NPWP           : "; cin.getline(form[z].scan_npwp,20); //cin.ignore();
    cout << "\t\t| Scan Salary Slip           : "; cin.getline(form[z].scan_slip,20); //cin.ignore();
	cout << "\t\t|                                               |"<<endl;
	cout << "\t\t|                                               |"<<endl;
    cout << "\t\t| ---Data_Applicant---                          |"<<endl;
    cout << "\t\t| Id_Number_KTP              : "; cin >>form[z].data.noktp; cin.ignore();
    cout << "\t\t| Name_Applicant_BasedOnID   : "; cin.getline(form[z].data.nama_app,20); //cin.ignore();
    cout << "\t\t| Current_Address            : "; cin.getline(form[z].data.address,20); //cin.ignore();
    cout << "\t\t| Number_Phone               : "; cin >>form[z].data.nohp; cin.ignore();
    cout << "\t\t| Email                      : "; cin.getline(form[z].data.email,20); //cin.ignore();
    cout << "\t\t| Leng_of_work               : "; cin.getline(form[z].data.lama_kerja,20); //cin.ignore();
    cout << "\t\t| Status_of_residence        : "; cin.getline(form[z].data.status_tinggal,20); 
	cout << "\t\t|                                               |"<<endl;
	cout << "\t\t|                                               |"<<endl;
    cout << "\t\t| ---Data_Company---                            |"<<endl;
    cout << "\t\t| Name_Company               : "; cin.getline(form[z].perusahaan.nama_perusahaan,50); //cin.ignore();
    cout << "\t\t| Company_Address            : "; cin.getline(form[z].perusahaan.tinggal_perusahaan,20); //cin.ignore();
    cout << "\t\t| Company_Phone_Number       : "; cin >>form[z].perusahaan.nohp_perusahaan; cin.ignore();
    cout << "\t\t| Job_Position               : "; cin.getline(form[z].perusahaan.posisi_perusahaan,20); //cin.ignore();
    cout << "\t\t| Division_of_work           : "; cin.getline(form[z].perusahaan.divisi_perusahaan,20); //cin.ignore();
	cout << "\t\t|                                               |"<<endl;
	cout << "\t\t|                                               |"<<endl;
    cout << "\t\t| ---Emergency_Contact---                       |"<<endl;
    cout << "\t\t| Name_contact               : "; cin.getline(form[z].darurat.namakontak_darurat,50); //cin.ignore();
    cout << "\t\t| Emergency_Address          : "; cin.getline(form[z].darurat.alamat_darurat,20); //cin.ignore();
    cout << "\t\t| Emergency_Number           : "; cin >>form[z].darurat.nohp_darurat; cin.ignore();
    cout << "\t\t| Emergency_contact_relation : "; cin.getline(form[z].darurat.hubungan_darurat,20); //cin.ignore();
	cout << "\t\t|                                               |"<<endl;
	cout << "\t\t|                                               |"<<endl;
    cout << "\t\t| ---Tenor---                                   |"<<endl;
    cout << "\t\t| amount_of_loan             : "; cin >>form[z].pinjam.jmlh_pinjam; //cin.ignore();
    cout << "\t\t| Number_Rekening_Transfer   : "; cin >>form[z].pinjam.norek; //cin.ignore();
    cout << "\t\t| Length_of_Loan             : "; cin >>form[z].pinjam.masa_pinjam; //cin.ignore();
	cout << "\t\t|                                               |"<<endl;
	cout << "\t\t|                                               |"<<endl;		
	cout << "\t\t|===============================================|"<<endl;
}

void input(){
	
	char get[1];
	system("cls");
     	head();
     	cout << "\t\t| ---Formulir Pinjaman---                        "<<endl;
     	cout << "\t\t| Kode_Peminjaman (max 5) : "; cin >> form[header].kode; cin.getline(get,1);
     	cout << "\t\t| Load_Tenor              : "; cin >>form[header].tenor; cin.ignore();
        cout << "\t\t| Nama Sales              : "; cin.getline(form[header].nama,20); //cin.ignore();
        cout << "\t\t| Tanggal Dan Waktu       : "; cin.getline(form[header].time,50); //cin.ignore();
        cout << "\t\t| Scan ID Number KTP ?    : "; cin >> form[header].scan_ktp; //cin.ignore(); 
        cout << "\t\t| Scan Number NPWP ?      : "; cin >> form[header].scan_npwp; cin.ignore();
        cout << "\t\t| Scan Salary Slip ?      : "; cin >> form[header].scan_slip; cin.ignore();
		cout << "\t\t|                                               "<<endl;
		cout << "\t\t|                                               "<<endl;
     	cout << "\t\t| ---Data Pemohon---                          "<<endl;
     	cout << "\t\t| No. KTP                 : "; cin >>form[header].data.noktp; cin.ignore();
        cout << "\t\t| Nama Pemohon            : "; cin.getline(form[header].data.nama_app,20); //cin.ignore();
        cout << "\t\t| Alamat Saat ini         : "; cin.getline(form[header].data.address,20); //cin.ignore();
        cout << "\t\t| No. HP                  : "; cin >>form[header].data.nohp; cin.ignore();
        cout << "\t\t| Email                   : "; cin >>form[header].data.email; cin.ignore();
        cout << "\t\t| Lama Berkerja           : "; cin.getline(form[header].data.lama_kerja,20); //cin.ignore();
        cout << "\t\t| Status Tempat Tinggal   : "; cin.getline(form[header].data.status_tinggal,20); 
		cout << "\t\t|                                               "<<endl;
		cout << "\t\t|                                               "<<endl;
     	cout << "\t\t| ---Data Perusahaan---                            "<<endl;
     	cout << "\t\t| Nama Perusahaan         : "; cin.getline(form[header].perusahaan.nama_perusahaan,50); //cin.ignore();
        cout << "\t\t| Alamat Perusahaan       : "; cin.getline(form[header].perusahaan.tinggal_perusahaan,20); //cin.ignore();
        cout << "\t\t| No.HP Perusahaan        : "; cin >>form[header].perusahaan.nohp_perusahaan; cin.ignore();
        cout << "\t\t| Posisi Kerja            : "; cin.getline(form[header].perusahaan.posisi_perusahaan,20); //cin.ignore();
        cout << "\t\t| Divisi Kerja            : "; cin.getline(form[header].perusahaan.divisi_perusahaan,20); //cin.ignore();
		cout << "\t\t|                                               "<<endl;
		cout << "\t\t|                                               "<<endl;
     	cout << "\t\t| ---Kontak Darurat---                       "<<endl;
     	cout << "\t\t| Nama Kontak             : "; cin.getline(form[header].darurat.namakontak_darurat,50); //cin.ignore();
        cout << "\t\t| Alamat Darurat          : "; cin.getline(form[header].darurat.alamat_darurat,20); //cin.ignore();
        cout << "\t\t| No.HP Darurat           : "; cin >>form[header].darurat.nohp_darurat; cin.ignore();
        cout << "\t\t| Hubungan Kontak Darurat : "; cin.getline(form[header].darurat.hubungan_darurat,20); //cin.ignore();
		cout << "\t\t|                                               "<<endl;
		cout << "\t\t|                                               "<<endl;
     	cout << "\t\t| ---Tenor---                                   "<<endl;
     	cout << "\t\t| Jumlah Pinjaman         : "; cin >>form[header].pinjam.jmlh_pinjam; //cin.ignore();
        cout << "\t\t| NO. Rekening Transfer   : "; cin >>form[header].pinjam.norek; //cin.ignore();
        cout << "\t\t| Jangka Pinjaman         : "; cin >>form[header].pinjam.masa_pinjam; //cin.ignore();
		cout << "\t\t|                                               "<<endl;
		cout << "\t\t|                                               "<<endl;		
		cout << "\t\t|===============================================|"<<endl;
		header++;
        system("pause");
}

void sort(){
 	int i, j ,tmp;
    cout<<endl;

    for( i=0;i<header;i++)
     {
          for(j=i+1;j<header;j++)
         {
              if(form[i].kode>form[j].kode)
             {
                 tmp=form[i].kode;
                 form[i].kode=form[j].kode;
                 form[j].kode=tmp;
                 
                 swap(form[j].nama,form[i].nama);
                 
                 tmp=form[i].pinjam.jmlh_pinjam;
                 form[i].pinjam.jmlh_pinjam=form[j].pinjam.jmlh_pinjam;
                 form[j].pinjam.jmlh_pinjam=tmp;
                 
                 tmp=form[i].tenor;
                 form[i].tenor=form[j].tenor;
                 form[j].tenor=tmp;
                 
             }
         }
     }
    head();
    cout << "\t\t|                                               |"<<endl;
	cout << "\t\t|===============================================|"<<endl;
	cout << "\t\t|                                               |"<<endl;
    cout << "\t\t| Data setelah diurutkan  :                     |"<<endl;
    cout << "\t\t|                                               |"<<endl;
    for(i=0; i<header; i++)
    {
    	{
		cout<<"\t\t| Kode Card                         : "<<form[i].kode<<endl;
 		cout<<"\t\t| Nama Customer                     : "<<form[i].nama<<endl;
 		cout<<"\t\t| Amount Of Loan                    : "<<form[i].pinjam.jmlh_pinjam<<endl;
 		cout<<"\t\t| Load Tenor                        : "<<form[i].tenor<<endl;
 		cout<<"\t\t| Status Form                       : Belum Lunas"<<endl;
 		cout << "\t\t|                                               |"<<endl;
		cout << "\t\t|===============================================|"<<endl;
 		cout<<endl<<endl;
        }
    }
 }

int main() {
	char menu;
	int header=0,x,y;
	int n,ar,p;
	n=1;
	int pilih;
	int namedit;
	//Application_form form[20];
	char get[1];
	bool ketemu;
  
	do{    
    system("cls");
    system ("color a");
    awal:
	head();
	cout << "\t\t|\tMENU UTAMA :                            |"<<endl;
	cout << "\t\t|                                               |"<<endl;
    cout << "\t\t|\t[1] Data Entry                          |"<<endl;
	cout << "\t\t|                                               |"<<endl;
    cout << "\t\t|\t[2] Quality Control                     |"<<endl;
	cout << "\t\t|                                               |"<<endl;
    cout << "\t\t|\t[3] Manage Report                       |"<<endl;
	cout << "\t\t|                                               |"<<endl;
    cout << "\t\t|\t[4] Keluar                              |"<<endl;
	cout << "\t\t|                                               |"<<endl;
	cout << "\t\t|===============================================|"<<endl;
    cout << "\n\tMasukan Pilihan Anda (1-4) : "; cin >> menu;
  
    if(menu == '1') {
    	input();
    }
  
    else if(menu == '2') {
    	system ("cls");
    	int pil;
    	head();
    	cout << "\t\t|       Pencarian Data & Quality Control        |"<<endl;
    	cout << "\t\t|                                               |"<<endl;
		cout << "\t\t|===============================================|"<<endl;
		cout << "\t\t|                                               |"<<endl;;
      	cout << "\t\t|\tMasukan Kode Pinjam : "; cin>>namedit;
    
    	for(x=0;x<=header;x++) {
     		if(namedit==form[x].kode) {
     			cout << "\t\t|                                               |"<<endl;
				cout << "\t\t|===============================================|"<<endl;
     			cout << "\t\t|                                               |"<<endl;
	        	cout << "\t\t|\tData di temukan                         |"<<endl;
				cout << "\t\t|\tData ke-" << x+1 <<"                               |"<< endl;
     			cout << "\t\t|                                               "<<endl;
	        	cout << "\t\t|Application Form                                "<<endl;
	        	cout << "\t\t|\tKode_Peminjaman   : " << form[x].kode << endl;
	        	cout << "\t\t|\tLoad_Tenor        : " << form[x].tenor << endl;
	        	cout << "\t\t|\tNama_Sales        : " << form[x].nama << endl;
	        	cout << "\t\t|\tDate_And_Time     : " << form[x].time << endl;
	        	cout << "\t\t|\tScan ID Number KTP: " << form[x].scan_ktp << endl;
	        	cout << "\t\t|\tScan Number NPWP  : " << form[x].scan_npwp << endl;
	        	cout << "\t\t|\tScan Salary Slip  : " <<form[x].scan_slip << endl;
	        	cout << "\t\t|                                               "<<endl;
	        	cout << "\t\t|Data Applicant                                 "<<endl;
	        	cout << "\t\t|\tId_Number_KTP     : " << form[x].data.noktp << endl;
	        	cout << "\t\t|\tName_Applicant    : " << form[x].data.nama_app << endl;
	        	cout << "\t\t|\tCurrent_Address   : " << form[x].data.address << endl;       	
	        	cout << "\t\t|\tNumber_Phone      : " << form[x].data.nohp << endl;
	        	cout << "\t\t|\tEmail             : " << form[x].data.email << endl;
	        	cout << "\t\t|\tLeng_of_work      : " << form[x].data.lama_kerja << endl;
	        	cout << "\t\t|\tStatus_of_residence: "<< form[x].data.status_tinggal <<endl;
	        	cout << "\t\t|                                               "<<endl;
	        	cout << "\t\t|Data Company                                   "<<endl;
	        	cout << "\t\t|\tName_Company      : " << form[x].perusahaan.nama_perusahaan << endl;
	        	cout << "\t\t|\tCompany_Address   : " << form[x].perusahaan.tinggal_perusahaan << endl;
	        	cout << "\t\t|\tCompany_Phone_Number: " << form[x].perusahaan.nohp_perusahaan << endl;
	        	cout << "\t\t|\tJob_Position      : " << form[x].perusahaan.posisi_perusahaan << endl;       	
	        	cout << "\t\t|\tDivision_of_work  : " << form[x].perusahaan.divisi_perusahaan << endl;
	        	cout << "\t\t|                                               "<<endl;
	        	cout << "\t\t|Emergency Contact                              "<<endl;
	        	cout << "\t\t|\tName_contact      : " << form[x].darurat.namakontak_darurat <<endl;
	        	cout << "\t\t|\tEmergency_Address : " << form[x].darurat.alamat_darurat <<endl;
	        	cout << "\t\t|\tEmergency_Number  : " << form[x].darurat.nohp_darurat << endl;
	        	cout << "\t\t|\tEmergency_contact_relation : " << form[x].darurat.hubungan_darurat << endl;
	        	cout << "\t\t|                                               "<<endl;
	        	cout << "\t\t|Tenor                                          "<<endl;
	        	cout << "\t\t|\tamount_of_loan    : " << form[x].pinjam.jmlh_pinjam << endl;       	
	        	cout << "\t\t|\tNumber_Rekening_Transfer : " << form[x].pinjam.norek << endl;
	        	cout << "\t\t|\tLength_of_Loan    : " << form[x].pinjam.masa_pinjam << endl;
	        	cout << "\t\t|                                               "<<endl;
        		
				cout<<"\t\t|\t1. Accept Dokumen ? "<<endl;
				cout<<"\t\t|\t2. Reject Dokumen ? "<<endl;
				cout<<"\t\t|\t3. Kembali Menu Awal "<<endl;
				cout<<"\t\t|\tMasukan Pilihan Anda (1/2/3) : "; cin>>pil;
				system("cls");
				if(pil==1){
					head();
        			cout << "\t\t|                                               |"<<endl;
					cout << "\t\t|===============================================|"<<endl;
					cout << "\t\t|                                               |"<<endl;
					cout << "\t\t|\tData Berhasil Di Accept                          |"<<endl;
        			cout << "\t\t|                                               |"<<endl;
					cout << "\t\t|===============================================|"<<endl;
					system("pause");
					system("cls");
				}
				else if(pil==2){
					system("cls");
					head();
        			cout << "\t\t|                                               |"<<endl;
					cout << "\t\t|\tData Rework Silahkan Isi Dengan Benar   |"<<endl;
					cout << "\t\t|                                               |"<<endl;
					cout << "\t\t|===============================================|"<<endl;
					cout << "\t\t|\tMasukan Kode Pinjam  : "; cin>>namedit;
					for(int x=0;x<=header;x++){
						if(namedit==form[x].kode){
							edit(x);
							system("cls");
						}
					}
				}
				else if(pil==3){
					system("cls");
					goto awal;
				}
			}
        	else{
        		cout << "\t\t|                                               |"<<endl;
				cout << "\t\t|===============================================|"<<endl;
				cout << "\t\t|                                               |"<<endl;
    			cout << "\t\t|    DATA YANG ANDA CARI TIDAK DI TEMUKAN !!!   |"<<endl;
    			system("pause");
			}
    	}
        
   }

 	else if(menu == '3') {
 		char lap;
    	system ("cls");
		head(); 
    	cout << "\t\t|                 MANAGE REPORT                 |"<<endl;
		cout << "\t\t|                                               |"<<endl;
		cout << "\t\t|===============================================|"<<endl;
		cout << "\t\t|                                               |"<<endl;
		cout << "\t\t|\t1. View (Read Only)                     |"<<endl;
		cout << "\t\t|\t2. Print (Notepad)                      |"<<endl;
		cout << "\t\t|\t3. Sorting (Ascending)                  |"<<endl;
		cout << "\t\t|                                               |"<<endl;
		cout<<  "\t\t|\tMasukan Pilihan Anda (1/2/3)  : "; cin>>lap;
		system("cls");
	
		if(lap== '1'){
			for(x=0;x<=header;x++) {
			head();
	    	cout << "\t\t|\tDatabase Data Penduduk ke-" << x+1 << endl;
			cout << "\t\t|                                               "<<endl;
			cout << "\t\t|Application Form                                "<<endl;
	       	cout << "\t\t|\tKode_Peminjaman   : " << form[x].kode << endl;
	       	cout << "\t\t|\tLoad_Tenor        : " << form[x].tenor << endl;
	       	cout << "\t\t|\tNama_Sales        : " << form[x].nama << endl;
	       	cout << "\t\t|\tDate_And_Time     : " << form[x].time << endl;
	       	cout << "\t\t|\tScan ID Number KTP: " << form[x].scan_ktp << endl;
	       	cout << "\t\t|\tScan Number NPWP  : " << form[x].scan_npwp << endl;
	       	cout << "\t\t|\tScan Salary Slip  : " <<form[x].scan_slip << endl;
	       	cout << "\t\t|                                               "<<endl;
	       	cout << "\t\t|Data Applicant                                 "<<endl;
	       	cout << "\t\t|\tId_Number_KTP     : " << form[x].data.noktp << endl;
	       	cout << "\t\t|\tName_Applicant    : " << form[x].data.nama_app << endl;
        	cout << "\t\t|\tCurrent_Address   : " << form[x].data.address << endl;       	
	       	cout << "\t\t|\tNumber_Phone      : " << form[x].data.nohp << endl;
	       	cout << "\t\t|\tEmail             : " << form[x].data.email << endl;
	       	cout << "\t\t|\tLeng_of_work      : " << form[x].data.lama_kerja << endl;
	       	cout << "\t\t|\tStatus_of_residence: "<< form[x].data.status_tinggal <<endl;
	       	cout << "\t\t|                                               "<<endl;
	       	cout << "\t\t|Data Company                                   "<<endl;
	       	cout << "\t\t|\tName_Company      : " << form[x].perusahaan.nama_perusahaan << endl;
	       	cout << "\t\t|\tCompany_Address   : " << form[x].perusahaan.tinggal_perusahaan << endl;
        	cout << "\t\t|\tCompany_Phone_Number: " << form[x].perusahaan.nohp_perusahaan << endl;
        	cout << "\t\t|\tJob_Position      : " << form[x].perusahaan.posisi_perusahaan << endl;       	
        	cout << "\t\t|\tDivision_of_work  : " << form[x].perusahaan.divisi_perusahaan << endl;
        	cout << "\t\t|                                               "<<endl;
	       	cout << "\t\t|Emergency Contact                              "<<endl;
	       	cout << "\t\t|\tName_contact      : " << form[x].darurat.namakontak_darurat <<endl;
	       	cout << "\t\t|\tEmergency_Address : " << form[x].darurat.alamat_darurat <<endl;
	       	cout << "\t\t|\tEmergency_Number  : " << form[x].darurat.nohp_darurat << endl;
	       	cout << "\t\t|\tEmergency_contact_relation : " << form[x].darurat.hubungan_darurat << endl;
	       	cout << "\t\t|                                               "<<endl;
	       	cout << "\t\t|Tenor                                          "<<endl;
	       	cout << "\t\t|\tamount_of_loan    : " << form[x].pinjam.jmlh_pinjam << endl;       	
        	cout << "\t\t|\tNumber_Rekening_Transfer : " << form[x].pinjam.norek << endl;
	       	cout << "\t\t|\tLength_of_Loan    : " << form[x].pinjam.masa_pinjam << endl;
	       	cout << "\t\t|                                               "<<endl;
			cout << "\t\t|===============================================|"<<endl;
  			}
  			system("pause");
		}
		else if(lap=='2'){
			for(i=0;i<=header;i++){
				report(i);
			}
			head();
			cout << "\t\t|                                               |"<<endl;
			cout << "\t\t|Data Berhasil di Simpan Di Notepad Laporan.txt |"<<endl;
			cout << "\t\t|                                               |"<<endl;
			cout << "\t\t|===============================================|"<<endl;	
			system("pause");
			system("cls");
			cout<<endl;
		}
		else if(lap=='3'){
			sort();
			system("pause");
			system("cls");
		}
		
		else{
			head();
			cout << "\t\t|                                               |"<<endl;
			cout<<"\t\t|Input yang anda masukan salah, silahkan ulang kembali";
			cout << "\t\t|                                               |"<<endl;
			cout << "\t\t|===============================================|"<<endl;
			system("pause");
		}
	}
}while(menu!='4');
  	system("cls");
    head();
     
    cout << "\t\t|                  TERIMA KASIH                 |" << endl;
	cout << "\t\t|                                               |"<<endl;
	cout << "\t\t|===============================================|"<<endl;
 	getch();
 	return 0;
}
