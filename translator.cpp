// File: translator.cpp
// Project: Genetic Code Translator
// Author: Pooja Verma (Starfire)
// Description: Translates RNA sequence into amino acids and generates an HTML report.

#include <iostream>     // For input/output operations
#include <fstream>      // For writing to HTML file
#include <map>          // To store codon-to-amino acid mapping
#include <string>       // To use string data type

using namespace std;

// Define a map (dictionary) to store RNA codons and their corresponding amino acids
map<string, string> codonTable = {
    {"AUG", "Methionine"}, {"UUU", "Phenylalanine"}, {"UUC", "Phenylalanine"},
    {"UUA", "Leucine"}, {"UUG", "Leucine"}, {"CUU", "Leucine"}, {"CUC", "Leucine"},
    {"CUA", "Leucine"}, {"CUG", "Leucine"}, {"AUU", "Isoleucine"}, {"AUC", "Isoleucine"},
    {"AUA", "Isoleucine"}, {"GUU", "Valine"}, {"GUC", "Valine"}, {"GUA", "Valine"},
    {"GUG", "Valine"}, {"UCU", "Serine"}, {"UCC", "Serine"}, {"UCA", "Serine"},
    {"UCG", "Serine"}, {"AGU", "Serine"}, {"AGC", "Serine"}, {"CCU", "Proline"},
    {"CCC", "Proline"}, {"CCA", "Proline"}, {"CCG", "Proline"}, {"ACU", "Threonine"},
    {"ACC", "Threonine"}, {"ACA", "Threonine"}, {"ACG", "Threonine"}, {"GCU", "Alanine"},
    {"GCC", "Alanine"}, {"GCA", "Alanine"}, {"GCG", "Alanine"}, {"UAU", "Tyrosine"},
    {"UAC", "Tyrosine"}, {"UAA", "Stop"}, {"UAG", "Stop"}, {"UGA", "Stop"},
    {"CAU", "Histidine"}, {"CAC", "Histidine"}, {"CAA", "Glutamine"}, {"CAG", "Glutamine"},
    {"AAU", "Asparagine"}, {"AAC", "Asparagine"}, {"AAA", "Lysine"}, {"AAG", "Lysine"},
    {"GAU", "Aspartic Acid"}, {"GAC", "Aspartic Acid"}, {"GAA", "Glutamic Acid"}, {"GAG", "Glutamic Acid"},
    {"UGU", "Cysteine"}, {"UGC", "Cysteine"}, {"UGG", "Tryptophan"}, {"CGU", "Arginine"},
    {"CGC", "Arginine"}, {"CGA", "Arginine"}, {"CGG", "Arginine"}, {"AGA", "Arginine"},
    {"AGG", "Arginine"}, {"GGU", "Glycine"}, {"GGC", "Glycine"}, {"GGA", "Glycine"},
    {"GGG", "Glycine"}
};

int main() {
    string rna;

    // Ask user to enter the RNA sequence
    cout << "Enter RNA sequence (e.g., AUGGCUUAA): ";
    cin >> rna;

    // Convert the input RNA string to uppercase (if entered in lowercase)
    for (char &c : rna) c = toupper(c);

    // Open an HTML file for output using ofstream
    ofstream html("dna_to_protein.html");

    // Write the HTML document's structure (head, style, and opening body)
    html << "<!DOCTYPE html>\n<html>\n<head><title>Genetic Code Translation</title>\n";

    // Add basic CSS styles for table formatting
    html << "<style>body{font-family:sans-serif;}table{border-collapse:collapse;margin-top:20px;}"
         << "td,th{border:1px solid #444;padding:10px;}th{background:#b0e0e6;}td{background:#f0f8ff;}</style>\n";

    html << "</head><body>\n";

    // Heading for the page
    html << "<h2>Genetic Code Translation Result</h2>\n";

    // Start the table and headers
    html << "<table>\n<tr><th>Codon</th><th>Amino Acid</th></tr>\n";

    // Loop through the RNA sequence in chunks of 3 letters (1 codon = 3 nucleotides)
    for (size_t i = 0; i + 2 < rna.length(); i += 3) {
        // Extract a codon from the sequence
        string codon = rna.substr(i, 3);

        // Find the matching amino acid from the codon table
        string aminoAcid = codonTable.count(codon) ? codonTable[codon] : "Invalid";

        // Add the codon and its corresponding amino acid to the HTML table
        html << "<tr><td>" << codon << "</td><td>" << aminoAcid << "</td></tr>\n";

        // Stop translation when a "Stop" codon is encountered
        if (aminoAcid == "Stop") break;
    }

    // Close the table and HTML tags
    html << "</table>\n</body>\n</html>";
    html.close(); // Save and close the HTML file

    // Show success message in terminal
    cout << "Translation complete! Open 'dna_to_protein.html' to view the result.\n";
    return 0;
}
