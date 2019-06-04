#include <iostream>
#include <fstream>

class Studentas {
private:
    int pazymiai[5];
public:
    Studentas();
    ~Studentas();

    void ivestiPazymius();
    double vidurkis();

    bool gausFinansavima();
    bool gausStipendija();
};

int main() {
    int stud_k = 0;
    std::cin >> stud_k;

    Studentas * studentas = new Studentas[stud_k];
    for (int i = 0; i < stud_k; i++)
        studentas[i].ivestiPazymius();

    double bendras_vid = 0., temp_vid = 0.;
    int negaus_finansavimo = 0,
        gaus_stipendija = 0;

    for (int i = 0; i < stud_k; i++) {
        if (!studentas[i].gausFinansavima())
            negaus_finansavimo++;
        if (studentas[i].gausStipendija())
            gaus_stipendija++;
        temp_vid += studentas[i].vidurkis();
    }
    bendras_vid = temp_vid / (double)stud_k;

    std::ofstream output_file ("duomenys.txt");
    output_file << "Visu vidurkis: " << bendras_vid
                << "\nNegaus finansavimo: " << negaus_finansavimo
                << "\nGaus stipendija: " << gaus_stipendija;
    
    output_file.close();
    delete [] studentas;
    studentas = NULL;
    return 0;
}

void Studentas::ivestiPazymius() {
    for (int i = 0; i < 5; i++)
        std::cin >> pazymiai[i];
}

double Studentas::vidurkis() {
    double temp = 0.;
    for (int i = 0; i < 5; i++)
        temp += pazymiai[i];

    return temp / 5.0;
}

bool Studentas::gausFinansavima() {
    if (this->vidurkis() < 6) return false;
    for (int i = 0; i < 5; i++)
        if (pazymiai[i] < 5) return false;
    return true;
}

bool Studentas::gausStipendija() {
    if (this->vidurkis() >= 9) return true;
    else return false;
}

Studentas::Studentas() {
    for (int i = 0; i < 5; i++)
        pazymiai[i] = 0;
}

Studentas::~Studentas() {}