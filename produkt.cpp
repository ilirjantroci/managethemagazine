#include <iostream>
#include <fstream>
#include<string>
using namespace std;

struct Produkt {  //fushat e produktit (kolonat)
 
    int kodi;
    string emri;
    float cmimi;
    string pershkrimi;
    float pesha;
    string kategoria;
};

void shtoProdukt() {  //Shto nje produkt ne sistem 
	
    Produkt produkt; //aksesimi i fushave te produktit
    cout << "\n\tShkruaj kodin : ";
    cin >> produkt.kodi;
    cout << "\n\tShkruaj emrin : ";
    cin.get();
    getline(cin, produkt.emri);
    cout << "\n\tShkruaj cmimin: ";
    cin >> produkt.cmimi;
    cout << "\n\tShkruaj pershkrimin : ";
    cin.get();
    getline(cin, produkt.pershkrimi);  //getline -> per te pranuar hapesirat gjate shkrimit
    cout << "\n\tShkruaj peshen: ";
    cin >> produkt.pesha;
    cout << "\n\tShkruaj kategorine : ";
    cin.get();
    getline(cin, produkt.kategoria);


    ofstream shtoTeDhenat; //perdorimi ofstream per te punuar me skedare
    
    shtoTeDhenat.open("produktet.txt", ios::app);  //krijimi i skedarit produktet.txt
    
	//shtimi i te dhenave (insert) ne skedarin produktet.txt
    shtoTeDhenat << "\n" << produkt.kodi ;
    shtoTeDhenat << "\n" << produkt.emri ;
    shtoTeDhenat << "\n" << produkt.cmimi ;
    shtoTeDhenat << "\n" << produkt.pershkrimi;
    shtoTeDhenat << "\n" << produkt.pesha;
    shtoTeDhenat << "\n" << produkt.kategoria;
    shtoTeDhenat.close();
    
 
    cout << "\n\tProdukti u ruajt me sukses \n";
}

void afisho(Produkt produkt) {  //Afisho te dhenat e produktit (rekordet)
   
    cout << "\n\tKodi : " << produkt.kodi;
    cout << "\n\tEmri : " << produkt.emri;
    cout << "\n\tCmimi : " << produkt.cmimi;
    cout << "\n\tPershkrimi : " << produkt.pershkrimi;
    cout << "\n\tPesha : " << produkt.pesha;
    cout << "\n\tKategoria : " << produkt.kategoria<<endl;
}

void listoProduktet(){  //Listo katalogun , listen e produkteve qe jane te regjistruara
	
	Produkt produkt;
	
    ifstream lexo;  //perdorimi i ifstream per te lexuar te dhena nga nje file 
    
    lexo.open("produktet.txt");
    
    cout << "\n\t--- Lista e produkteve --- \n";
    
    while (!lexo.eof()) {
      
        lexo >> produkt.kodi;
        lexo.ignore();
        getline(lexo, produkt.emri);
        lexo >> produkt.cmimi;
        lexo.ignore();
        getline(lexo, produkt.pershkrimi);
        lexo >> produkt.pesha;
        lexo.ignore();
        getline(lexo, produkt.kategoria);
        
        afisho(produkt);
    }
    lexo.close();
}

int kerkoProdukt(){  //Kerko nje produkt ne baze te kodit te produktit
	
	int kodi;  //kodi qe do te kerkohet
	
    cout << "\n\tShkruani kodin e produktit qe doni te kerkoni : ";
    cin >> kodi;
    
    Produkt produkt;
    
    ifstream lexo;
    lexo.open("produktet.txt");
    
    while (!lexo.eof()) {
    	
        lexo >> produkt.kodi;
        
        lexo.ignore();
        getline(lexo, produkt.emri);
        lexo >> produkt.cmimi;
        lexo.ignore();
        getline(lexo, produkt.pershkrimi);
        lexo >> produkt.pesha;
        lexo.ignore();
        getline(lexo, produkt.kategoria);
        
        if (produkt.kodi == kodi) {
        	
            afisho(produkt);
            
            return kodi;

        }
    }
    
}

void kerkoProduktEmri(){  //Kerko nje produkt ne baze te emrit te produktit
	
	string emri; //emri i produktit qe do te kerkohet
	
    cout << "\n\tShkruani emrin e produktit qe doni te kerkoni : ";
    cin.get();
    getline(cin, emri);
    
    Produkt produkt;
    
    ifstream lexo;
    lexo.open("produktet.txt");
    
    while (!lexo.eof()) {
    	
        lexo >> produkt.kodi;
        lexo.ignore();
        getline(lexo, produkt.emri);
        lexo >> produkt.cmimi;
        lexo.ignore();
        getline(lexo, produkt.pershkrimi);
        lexo >> produkt.pesha;
        lexo.ignore();
        getline(lexo, produkt.kategoria);
        
        if (produkt.emri == emri) {
        	
            afisho(produkt);
        }
    }
}

void ndryshoProdukt(){ //Ndrysho te dhenat e nje produkti
	
	int kodi = kerkoProdukt();  // kerkojme produktin qe do te modifikojme , kodi vjen nga return kodi; ne funksionin kerkoProdukt; 
	
    cout << "\n\tA deshironi te ndryshoni te dhenat e ketij produkti (po/jo) : ";
    
    string vendimi;
    
    cin >> vendimi;
    
    if (vendimi == "po") {
    	
        Produkt infoProdukt;
  
	    cout << "\n\tShkruaj emrin : ";
	    cin.get();
	    getline(cin, infoProdukt.emri);
	    cout << "\n\tShkruaj cmimin: ";
	    cin >> infoProdukt.cmimi;
	    cout << "\n\tShkruaj pershkrimin : ";
	    cin.get();
	    getline(cin, infoProdukt.pershkrimi);
	    cout << "\n\tShkruaj peshen: ";
	    cin >> infoProdukt.pesha;
	    cout << "\n\tShkruaj kategorine : ";
	    cin.get();
	    getline(cin, infoProdukt.kategoria);
        
        Produkt produkt;
        
        ofstream tempFile;
        tempFile.open("testprodukt.txt");
        
        ifstream lexo;
        lexo.open("produktet.txt");
        
        while (!lexo.eof()) {
        	
            lexo >> produkt.kodi;
	        lexo.ignore();
	        getline(lexo, produkt.emri);
	        lexo >> produkt.cmimi;
	        lexo.ignore();
	        getline(lexo, produkt.pershkrimi);
	        lexo >> produkt.pesha;
	        lexo.ignore();
	        getline(lexo, produkt.kategoria);
	        
	        
            if (produkt.kodi != kodi) {
            	
                tempFile << "\n" << produkt.kodi;
                tempFile << "\n" << produkt.emri;
                tempFile << "\n" << produkt.cmimi;
                tempFile << "\n" << produkt.pershkrimi;
                tempFile << "\n" << produkt.pesha;
                tempFile << "\n" << produkt.kategoria;
            }
            else {
                tempFile << "\n"<< produkt.kodi;
                tempFile << "\n"<< infoProdukt.emri;
                tempFile << "\n"<< infoProdukt.cmimi;
                tempFile << "\n" << infoProdukt.pershkrimi;
                tempFile << "\n"<< infoProdukt.pesha;
                tempFile << "\n"<< infoProdukt.kategoria;
            }
        }
        lexo.close();
        tempFile.close();
        remove("produktet.txt");
        rename("testprodukt.txt", "produktet.txt");
        cout << "\n\tTe dhenat u ndryshuan me sukses";
    }
    else {
        cout << "\n\tNdryshimi i te dhenave u anullua";
    }
}

void fshijProdukt(){ //Fshij nje produkt nga katalogu
	
	int kodi = kerkoProdukt(); // kerkojme produktin qe do te modifikojme , kodi vjen nga return kodi; ne funksionin kerkoProdukt; 
	
    cout << "\n\tA deshironi te fshini kete produkt (po/jo) : ";
    
    string vendimi;
    
    cin >> vendimi;
    
    if (vendimi == "po") {
    	
        Produkt produkt;
        
        ofstream tempFile;
        tempFile.open("testprodukt.txt");
        
        ifstream lexo;
        lexo.open("produktet.txt");
        
        while (!lexo.eof()) {
        	
            lexo >> produkt.kodi;
	        lexo.ignore();
	        getline(lexo, produkt.emri);
	        lexo >> produkt.cmimi;
	        lexo.ignore();
	        getline(lexo, produkt.pershkrimi);
	        lexo >> produkt.pesha;
	        lexo.ignore();
	        getline(lexo, produkt.kategoria);
            
            if (produkt.kodi != kodi) {
            	
                tempFile << "\n" << produkt.kodi;
                tempFile << "\n" << produkt.emri;
                tempFile << "\n" << produkt.cmimi;
                tempFile << "\n" << produkt.pershkrimi;
                tempFile << "\n" << produkt.pesha;
                tempFile << "\n" << produkt.kategoria;
            }
        }
        lexo.close();
        tempFile.close();
        remove("produktet.txt");
        rename("testprodukt.txt", "produktet.txt");
        cout << "\n\tProdukti u fshi me sukses";
    }
    else {
        cout << "\n\tFshirja e produktit u anullua!";
    }
    
}

int main()
{

    while (true) { //Afisho menut ne cdo faqe ( true ) 
    	
    	//Afisho menut ne forme liste 
    	
        cout << "\n\t1.Shto nje produkt";
        cout << "\n\t2.Lista e produkteve";
        cout << "\n\t3.Kerko per produkt sipas kodit";
        cout << "\n\t4.Kerko per produkt sipas emrit";
        cout << "\n\t5.Ndrysho nje produkt";
        cout << "\n\t6.Fshij nje produkt\n\n";
        

        int menu;
        cout << "\n\tPerzgjidh menun : ";
        cin >> menu;  //Shkruaj menun qe do te aksesosh (perdoresh)
        switch (menu) {
        case 1:
            shtoProdukt();
            break;
        case 2:
            listoProduktet();
            break;
        case 3:
            kerkoProdukt();
            break;
        case 4:
        	kerkoProduktEmri();
        	break;
        case 5:
        	ndryshoProdukt();
            break; 
        case 6:
        	fshijProdukt();
            break;
        }
     }
    

}



/*
	T?? nd??rtohet programi ne c++ q?? menaxhon nj?? magazin??.
	
    Detyrat qe do zgjidh?? programi.
    Regjistrimi i nj?? produkti t?? ri (Insert product)  
    Visualizim lista e katalogut te produkteve ne magazine tashme te regjistruar
    K??rkim i produktit ne baze te kodit te tij  
    K??rkim i produktit ne baze emri(product name)  
    Ndryshimi(modifikimi) i te dh??nave p??r ??do produkt  
    Regjistrimi i te dh??nave dhe ruajtja e tyre ne disk(storage)
    Krijimi i tabelave p??r faturat e produkteve
    
    ********************************
    
    Universiteti "Aleksand??r Moisiu" Durr??s - UAMD
    
    Lenda : Programim ne c++

	https://github.com/ilirjantroci/managethemagazine
*/


