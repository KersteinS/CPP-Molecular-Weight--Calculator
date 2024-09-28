#ifndef PERIODIC_TOOLS_H
#define PERIODIC_TOOLS_H
#include <string>
#include <map>

namespace periodic_tools {

class PeriodicTable
{
public:
struct PERIODIC_ELEMENT
    {
        int atomic_number;
        std::string atomic_symbol;
        std::string atomic_name;
        double atomic_weight;
    };
private:
    std::map<std::string, PERIODIC_ELEMENT> Elements {
        {"H",{1, "H", "Hydrogen", 1.00797}},
        {"He",{2, "He", "Helium", 4.0026}},
        {"Li",{3, "Li", "Lithium", 6.941}},
        {"Be",{4, "Be", "Beryllium", 9.01218}},
        {"B",{5, "B", "Boron", 10.81}},
        {"C",{6, "C", "Carbon", 12.011}},
        {"N",{7, "N", "Nitrogen", 14.0067}},
        {"O",{8, "O", "Oxygen", 15.9994}},
        {"F",{9, "F", "Fluorine", 18.998403}},
        {"Ne",{10, "Ne", "Neon", 20.179}},
        {"Na",{11, "Na", "Sodium", 22.98977}},
        {"Mg",{12, "Mg", "Magnesium", 24.305}},
        {"Al",{13, "Al", "Aluminum", 26.98154}},
        {"Si",{14, "Si", "Silcon", 28.0855}},
        {"P",{15, "P", "Phosphorus", 30.97376}},
        {"S",{16, "S", "Sulfur", 32.06}},
        {"Cl",{17, "Cl", "Chlorine", 35.453}},
        {"Ar",{18, "Ar", "Argon", 39.948}},
        {"K",{19, "K", "Potassium", 39.0983}},
        {"Ca",{20, "Ca", "Calcium", 40.08}},
        {"Sc",{21, "Sc", "Scandium", 44.9559}},
        {"Ti",{22, "Ti", "Titanium", 47.9}},
        {"V",{23, "V", "Vanadium", 50.9415}},
        {"Cr",{24, "Cr", "Chromium", 51.996}},
        {"Mn",{25, "Mn", "Manganese", 54.938}},
        {"Fe",{26, "Fe", "Iron", 55.847}},
        {"Ni",{27, "Ni", "Nickel", 58.7}},
        {"Co",{28, "Co", "Cobalt", 58.9332}},
        {"Cu",{29, "Cu", "Copper", 63.546}},
        {"Zn",{30, "Zn", "Zinc", 65.38}},
        {"Ga",{31, "Ga", "Gallium", 69.72}},
        {"Ge",{32, "Ge", "Germanium", 72.59}},
        {"As",{33, "As", "Arsenic", 74.9216}},
        {"Se",{34, "Se", "Selenium", 78.96}},
        {"Br",{35, "Br", "Bromine", 79.904}},
        {"Kr",{36, "Kr", "Krypton", 83.8}},
        {"Rb",{37, "Rb", "Rubidium", 85.4678}},
        {"Sr",{38, "Sr", "Strontium", 87.62}},
        {"Y",{39, "Y", "Yttrium", 88.9059}},
        {"Zr",{40, "Zr", "Zirconium", 91.22}},
        {"Nb",{41, "Nb", "Niobium", 92.9064}},
        {"Mo",{42, "Mo", "Molybdenum", 95.94}},
        {"Tc",{43, "Tc", "Technetium", 98.0}},
        {"Ru",{44, "Ru", "Ruthenium", 101.07}},
        {"Rh",{45, "Rh", "Rhodium", 102.9055}},
        {"Pd",{46, "Pd", "Palladium", 106.4}},
        {"Ag",{47, "Ag", "Silver", 107.868}},
        {"Cd",{48, "Cd", "Cadmium", 112.41}},
        {"In",{49, "In", "Indium", 114.82}},
        {"Sn",{50, "Sn", "Tin", 118.69}},
        {"Sb",{51, "Sb", "Antimony", 121.75}},
        {"Te",{52, "Te", "Tellurium", 127.6}},
        {"I",{53, "I", "Iodine", 126.9045}},
        {"Xe",{54, "Xe", "Xenone", 131.3}},
        {"Cs",{55, "Cs", "Caesium", 132.9054}},
        {"Ba",{56, "Ba", "Barium", 137.33}},
        {"La",{57, "La", "Lanthanum", 138.9055}},
        {"Ce",{58, "Ce", "Cerium", 140.12}},
        {"Pr",{59, "Pr", "Praseodymium", 140.9077}},
        {"Nd",{60, "Nd", "Neodymium", 144.24}},
        {"Pm",{61, "Pm", "Promethium", 145.0}},
        {"Sm",{62, "Sm", "Samarium", 150.4}},
        {"Eu",{63, "Eu", "Europium", 151.96}},
        {"Gd",{64, "Gd", "Gadolinium", 157.25}},
        {"Tb",{65, "Tb", "Terbium", 158.9254}},
        {"Dy",{66, "Dy", "Dysprosium", 162.5}},
        {"Ho",{67, "Ho", "Holmium", 164.9304}},
        {"Er",{68, "Er", "Erbium", 167.26}},
        {"Tm",{69, "Tm", "Thulium", 168.9342}},
        {"Yb",{70, "Yb", "Ytterbium", 173.04}},
        {"Lu",{71, "Lu", "Lutetium", 174.967}},
        {"Hf",{72, "Hf", "Hafnium", 178.49}},
        {"Ta",{73, "Ta", "Tantalum", 180.9479}},
        {"W",{74, "W", "Tungsten", 183.85}},
        {"Re",{75, "Re", "Rhenium", 186.207}},
        {"Os",{76, "Os", "Osmium", 190.2}},
        {"Ir",{77, "Ir", "Iridium", 192.22}},
        {"Pt",{78, "Pt", "Platinum", 195.09}},
        {"Au",{79, "Au", "Gold", 196.9665}},
        {"Hg",{80, "Hg", "Mercury", 200.59}},
        {"Tl",{81, "Tl", "Thallium", 204.37}},
        {"Pb",{82, "Pb", "Lead", 207.2}},
        {"Bi",{83, "Bi", "Bismuth", 208.9804}},
        {"Po",{84, "Po", "Polonium", 209.0}},
        {"At",{85, "At", "Astatine", 210.0}},
        {"Rn",{86, "Rn", "Radon", 222.0}},
        {"Fr",{87, "Fr", "Francium", 223.0}},
        {"Ra",{88, "Ra", "Radium", 226.0254}},
        {"Ac",{89, "Ac", "Actinium", 227.0278}},
        {"Th",{90, "Th", "Thorium", 232.0381}},
        {"Pa",{91, "Pa", "Protactinium", 231.0359}},
        {"U",{92, "U", "Uranium", 238.029}},
        {"Np",{93, "Np", "Neptunium", 237.0482}},
        {"Pu",{94, "Pu", "Plutonium", 242.0}},
        {"Am",{95, "Am", "Americium", 243.0}},
        {"Cm",{96, "Cm", "Curium", 247.0}},
        {"Bk",{97, "Bk", "Berkelium", 247.0}},
        {"Cf",{98, "Cf", "Californium", 251.0}},
        {"Es",{99, "Es", "Einsteinium", 252.0}},
        {"Fm",{100, "Fm", "Fermium", 257.0}},
        {"Md",{101, "Md", "Mendelevium", 258.0}},
        {"No",{102, "No", "Nobelium", 250.0}},
        {"Lr",{103, "Lr", "Lawrencium", 260.0}},
        {"Rf",{104, "Rf", "Rutherfordium", 261.0}},
        {"Db",{105, "Db", "Dubnium", 262.0}},
        {"Sg",{106, "Sg", "Seaborgium", 263.0}},
        {"Bh",{107, "Bh", "Bohrium", 262.0}},
        {"Hs",{108, "Hs", "Hassium", 255.0}},
        {"Mt",{109, "Mt", "Meitnerium", 256.0}},
        {"Ds",{110, "Ds", "Darmstadtium", 281.0}},
        {"Rg",{111, "Rg", "Roentgenium", 281.0}},
        {"Cn",{112, "Cn", "Copernicium", 285.0}},
        {"Nh",{113, "Nh", "Nihonium", 286.0}},
        {"Fl",{114, "Fl", "Flerovium", 289.0}},
        {"Mc",{115, "Mc", "Moscovium", 289.0}},
        {"Lv",{116, "Lv", "Livermorium", 293.0}},
        {"Ts",{117, "Ts", "Tennessine", 293.0}},
        {"Og",{118, "Og", "Oganesson", 294.0}}
    };
public:
    PERIODIC_ELEMENT find(std::string key){
        std::map<std::string, periodic_tools::PeriodicTable::PERIODIC_ELEMENT>::iterator check = Elements.find(key);
        if (check == Elements.end()){
            return PERIODIC_ELEMENT {0,"","",0};
        }
        else {
            return Elements.find(key)->second;
        }
    };
    PeriodicTable(){};
    ~PeriodicTable(){};
};
}
#endif