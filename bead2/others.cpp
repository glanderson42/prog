#include "enor.h"

enum Exception {
    WI
};

Results::Results(std::string i, std::string t, double s) {
        identy = i;
        typeOfFish = t;
        sizeOfFish = s;
    }
std::string Results::getIdenty() {
        return identy;
    }
std::string Results::getTypeOfFish() {
        return typeOfFish;
    }
double Results::getSizeOfFish() {
        return sizeOfFish;
    }
std::istream& operator>>(std::istream &in, Results &r) {
    in >> r.identy >> r.typeOfFish >> r.sizeOfFish;
    return in;
}

std::ostream& operator<<(std::ostream &out,const Results& r) {
    out << r.identy << " " << r.typeOfFish << " " << r.sizeOfFish << std::endl;
    return out;
}

void outResults::setIdent(std::string n) {
        ident = n;
    }
void outResults::setType(std::string t) {
        type = t;
    }
void outResults::setMaxFish(double s) {
        maxFish = s;
    }
std::string outResults::getIdent() {
        return ident;
    }
std::string outResults::getType() {
        return type;
    }
double outResults::getMaxFish() {
        return maxFish;
    }

Enor::Enor(std::string fn) {
        filename = fn;
    }
void Enor::init() {
    f.open(filename.c_str());
    if(f.fail() || !f.is_open()) {
            throw WI;
        }
    }
void Enor::first() {
    f >> Data;
    Enor::next();
    }
void Enor::next() {
    if(f.fail()) {
        endIs = true;
    }
    cur.setIdent(Data.getIdenty());
    cur.setType(Data.getTypeOfFish());
    cur.setMaxFish(Data.getSizeOfFish());
    f >> Data;
    while (!f.fail() && Data.getIdenty() == cur.getIdent()) {
        if (cur.getMaxFish() < Data.getSizeOfFish()) {
            cur.setType(Data.getTypeOfFish());
            cur.setMaxFish(Data.getSizeOfFish());
        }
        f >> Data;
    }
}

bool Enor::isEnd() {
    return endIs;
}
outResults Enor::current() {
    return cur;
}
std::ostream& operator<<(std::ostream &out, const outResults& os) {
    out << os.ident << " " << os.type << " " << os.maxFish << std::endl;
}

void doIt(std::string fn) {
    std::cin >> fn;
    Enor en(fn);
    en.init();

    for (en.first(); !en.isEnd(); en.next()) {
        std::cout << en.current();
    }
}

void echoTask() {
    std::cout << "Egy horgaszversenyen valahanyszor egy versenyzo halat fog, feljegyzik egy szoveges" << std::endl;
    std::cout << "allomany soron kovetkezo soraba a versenyzo azonositojat (negyjegyu szam), a hal" << std::endl;
    std::cout << "fajtajanak nevet (ponty, keszeg, sullo, stb.) es a hal meretet. Feltehetjuk, hogy a szoveges" << std::endl;
    std::cout << "allomany helyesen van kitoltve: minden soraban harom adat van (azonosito, halfajta," << std::endl;
    std::cout << "meret) szokozokkel vagy tabulatorjelekkel elvalasztva. A verseny vegen a szoveges" << std::endl;
    std::cout << "allomany sorait azonosito szerint sorba rendezik. Irjuk ki a konzolra minden versenyzorol" << std::endl;
    std::cout << "azt, hogy melyik halbol fogta a leghosszabbat es mekkorat! " << std::endl;
}

void readFromFile(std::string &fn) {
    try {
        doIt(fn);
    }catch(Exception e) {
        switch(e) {
        case WI:
            std::cout << "Wrong Input" << std::endl;
            std::cout << "A file nev hibas! Adjon meg letezo filenevet!" << std::endl;
            readFromFile(fn);
            break;
        }
    }
}


void echoMenu(std::string &fn) {

    fn.clear();

    bool menuSuccess=false;
    do{

        system("cls");
        std::cout << "||=============================================||" <<  std::endl;
        std::cout << "||" << "Valasszon a lehetosegek kozul: " << "              ||" << std::endl;
        std::cout << "||" << "1, Feladat leiras                            ||" << std::endl;
        std::cout << "||" << "2, Filebol valo beolvasas" << "                    ||" << std::endl;
        std::cout << "||" << "3, Kilepes" << "                                   ||" << std::endl;
        std::cout << "||" << "Usson le egy billentyut" << "                      ||" << std::endl;
        std::cout << "||" << "=============================================" << "||" << std::endl;
        char input;
        input = getch();
        switch(input){
            case '1': {
                echoTask();
                menuSuccess = true;
                system("pause");
                break;
            }
            case '2': {
                std::cout << "Adja meg az input filet!" << std::endl;
                readFromFile(fn);
                menuSuccess = true;
                system("pause");
                break;
            }
            case '3':{
                std::cout << "Sikeresen kilepett a programbol" << std::endl;
                menuSuccess = true;
                exit(0);
                system("pause");
                break;
            }
            default:
                std::cout << "Wrong input" << std::endl;
                system("pause");
                break;
        }
    }while(!menuSuccess);
}

