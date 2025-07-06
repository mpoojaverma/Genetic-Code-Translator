// translator.cpp
// Author: Starfire (Pooja Verma)
// Created On: 07-07-2025
// Description: Takes RNA sequence input and generates a styled HTML file showing codon to amino acid translation.

#include <iostream>
#include <fstream>
#include <map>
using namespace std;

map<string, string> codonTable = {
    {"AUG", "Methionine (Start)"}, {"UUU", "Phenylalanine"}, {"UUC", "Phenylalanine"},
    {"UUA", "Leucine"}, {"UUG", "Leucine"},
    {"UCU", "Serine"}, {"UCC", "Serine"}, {"UCA", "Serine"}, {"UCG", "Serine"},
    {"UAU", "Tyrosine"}, {"UAC", "Tyrosine"},
    {"UGU", "Cysteine"}, {"UGC", "Cysteine"},
    {"UGG", "Tryptophan"},
    {"UAA", "STOP"}, {"UAG", "STOP"}, {"UGA", "STOP"},
    // Add more codons as needed...
};

string getAminoAcid(string codon) {
    if (codonTable.count(codon)) return codonTable[codon];
    else return "Invalid";
}

int main() {
    string rna;
    cout << "Enter RNA sequence (e.g., AUGGCUUAA): ";
    cin >> rna;

    ofstream html("index.html");

    html << "<!DOCTYPE html>\n<html>\n<head>\n<title>RNA to Protein</title>\n";
    html << "<style>\n";
    html << "body { font-family: Arial; padding: 20px; background-color: #f9f9f9; }\n";
    html << "h1 { color: #4CAF50; }\n";
    html << "table { border-collapse: collapse; width: 100%; }\n";
    html << "th, td { border: 1px solid #ccc; padding: 8px; text-align: center; }\n";
    html << "tr:nth-child(even) { background-color: #f2f2f2; }\n";
    html << ".start { color: green; font-weight: bold; }\n";
    html << ".stop { color: red; font-weight: bold; }\n";
    html << "</style>\n</head>\n<body>\n";

    html << "<h1>RNA to Protein Translation</h1>\n";
    html << "<p><strong>Input RNA:</strong> " << rna << "</p>\n";
    html << "<table>\n<tr><th>Codon</th><th>Amino Acid</th></tr>\n";

    for (size_t i = 0; i + 2 < rna.length(); i += 3) {
        string codon = rna.substr(i, 3);
        string aa = getAminoAcid(codon);

        string className = "";
        if (aa.find("Start") != string::npos) className = "start";
        else if (aa == "STOP") className = "stop";

        html << "<tr><td>" << codon << "</td><td class='" << className << "'>" << aa << "</td></tr>\n";

        if (aa == "STOP") break;
    }

    html << "</table>\n</body>\n</html>";

    html.close();

    cout << "✅ Translation complete! Open 'index.html' in browser to view the result.\n";

    return 0;
}
