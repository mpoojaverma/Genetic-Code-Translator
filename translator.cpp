// logic.cpp
// RNA to Protein Translation Logic in C++
// Author: Pooja Verma 🌿

#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, string> codonTable = {
        {"AUG", "Methionine (Start)"}, {"UUU", "Phenylalanine"}, {"UUC", "Phenylalanine"},
        {"UUA", "Leucine"}, {"UUG", "Leucine"},
        {"UCU", "Serine"}, {"UCC", "Serine"}, {"UCA", "Serine"}, {"UCG", "Serine"},
        {"UAU", "Tyrosine"}, {"UAC", "Tyrosine"},
        {"UGU", "Cysteine"}, {"UGC", "Cysteine"},
        {"UGG", "Tryptophan"},
        {"UAA", "STOP"}, {"UAG", "STOP"}, {"UGA", "STOP"}
    };

    string rna;
    cout << "Enter RNA sequence (e.g., AUGUCUUAA): ";
    cin >> rna;

    cout << "\nCodon\t→\tAmino Acid\n";
    for (size_t i = 0; i + 2 < rna.length(); i += 3) {
        string codon = rna.substr(i, 3);
        string aminoAcid = codonTable.count(codon) ? codonTable[codon] : "Invalid";
        cout << codon << "\t→\t" << aminoAcid << endl;
        if (aminoAcid == "STOP") break;
    }

    return 0;
}
