//=====> Ziad Mohamed Khalil Ibrahim <=====
//=====> 17100315 <=====

#include <iostream>
#include <fstream>
#include <vector>
#include<algorithm>
#include<string>
#include<regex>
#include<math.h>
#include <bits/stdc++.h> 
using namespace std;

void createMap(unordered_map<string, char> *um) 
{ 
    (*um)["0000"] = '0'; 
    (*um)["0001"] = '1'; 
    (*um)["0010"] = '2'; 
    (*um)["0011"] = '3'; 
    (*um)["0100"] = '4'; 
    (*um)["0101"] = '5'; 
    (*um)["0110"] = '6'; 
    (*um)["0111"] = '7'; 
    (*um)["1000"] = '8'; 
    (*um)["1001"] = '9'; 
    (*um)["1010"] = 'A'; 
    (*um)["1011"] = 'B'; 
    (*um)["1100"] = 'C'; 
    (*um)["1101"] = 'D'; 
    (*um)["1110"] = 'E'; 
    (*um)["1111"] = 'F'; 
} 
  
// function to find hexadecimal  
// equivalent of binary 
string convertBinToHex(string bin) 
{ 
    int l = bin.size(); 
    int t = bin.find_first_of('.'); 
      
    // length of string before '.' 
    int len_left = t != -1 ? t : l; 
      
    // add min 0's in the beginning to make 
    // left substring length divisible by 4  
    for (int i = 1; i <= (4 - len_left % 4) % 4; i++) 
        bin = '0' + bin; 
      
    // if decimal point exists     
    if (t != -1)     
    { 
        // length of string after '.' 
        int len_right = l - len_left - 1; 
          
        // add min 0's in the end to make right 
        // substring length divisible by 4  
        for (int i = 1; i <= (4 - len_right % 4) % 4; i++) 
            bin = bin + '0'; 
    } 
      
    // create map between binary and its 
    // equivalent hex code 
    unordered_map<string, char> bin_hex_map; 
    createMap(&bin_hex_map); 
      
    int i = 0; 
    string hex = ""; 
      
    while (1) 
    { 
        // one by one extract from left, substring 
        // of size 4 and add its hex code 
        hex += bin_hex_map[bin.substr(i, 4)]; 
        i += 4; 
        if (i == bin.size()) 
            break; 
              
        // if '.' is encountered add it 
        // to result 
        if (bin.at(i) == '.')     
        { 
            hex += '.'; 
            i++; 
        } 
    } 
      
    // required hexadecimal number 
    return hex;     
}

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

//Defines a regular expression that removes multiple spaces with one space
std::regex space_re(R"(\s+)");

//Removes Extra Space
inline std::string trim(const std::string &s)
{
   auto wsfront=std::find_if_not(s.begin(),s.end(),[](int c){return std::isspace(c);});
   auto wsback=std::find_if_not(s.rbegin(),s.rend(),[](int c){return std::isspace(c);}).base();
   return (wsback<=wsfront ? std::string() : std::string(wsfront,wsback));
}

//Splits the string into a vector of strings
vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

int hexaToDecimal(string num) {
    int i, r, len, hex = 0;

    len = num.size();

    for (i = 0; num[i] != '\0'; i++)

    {
        len--;
        if(num[i] >= '0' && num[i] <= '9')
            r = num[i] - 48;

        else if(num[i] >= 'a' && num[i] <= 'f')
                r = num[i] - 87;

             else if(num[i] >= 'A' && num[i] <= 'F')
                    r = num[i] - 55;

        hex += r * pow(16,len);
    }

    return hex;
}

string hexaToBin(string hexdec) 
{ 
    long int i = 0; 
    string output = "";
    while (hexdec[i]) { 
  
        switch (hexdec[i]) { 
        case '0': 
            output += "0000"; 
            break; 
        case '1': 
            output += "0001"; 
            break; 
        case '2': 
            output += "0010"; 
            break; 
        case '3': 
            output += "0011"; 
            break; 
        case '4': 
            output += "0100"; 
            break; 
        case '5': 
            output += "0101"; 
            break; 
        case '6': 
            output += "0110"; 
            break; 
        case '7': 
            output += "0111"; 
            break; 
        case '8': 
            output += "1000"; 
            break; 
        case '9': 
            output += "1001"; 
            break; 
        case 'A': 
        case 'a': 
            output += "1010"; 
            break; 
        case 'B': 
        case 'b': 
            output += "1011"; 
            break; 
        case 'C': 
        case 'c': 
            output += "1100"; 
            break; 
        case 'D': 
        case 'd': 
            output += "1101"; 
            break; 
        case 'E': 
        case 'e': 
            output += "1110"; 
            break; 
        case 'F': 
        case 'f': 
            output += "1111"; 
            break; 
        default: 
            cout << "\nInvalid hexadecimal digit "
                 << hexdec[i]; 
        } 
        i++; 
    } 
    
    return output;
} 

//Converts from decimal to hexadecimal
string decimalToHexa(int num) {
    std::stringstream ss;
    ss<< std::hex << num; // int decimal_value
    std::string res ( ss.str() );

    return res;
    
}

//Returns the index of a certain element/key
int findElement(vector<string> v, string key) {
    int index;
    
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == key) {
			index = i;
			break;
		}
	}
		
	return index;
}

bool contains(vector<string> v, string key) {
    int index;
    
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == key) {
			index = i;
			return true;
		}
	}
		
	return false;
}

string findInTable(int i, vector<string> locctrs_strings) {
    return locctrs_strings.at(i);
}

string findPC(int i, vector<string> locctrs_strings) {
    return locctrs_strings.at(i + 1);
}

string findBase() {
    return "33";
}

string fillBits(string input, int n) {
    while(input.length() != n) {
        input.insert(0, "0");
    }
    
    return input;
}

string transformToHexa(string input) {
    string  temp = "";
    string output = "";
    for(int i = 0; i < input.size(); i += 4) {
        temp += input[i];
        temp += input[i + 1];
        temp += input[i + 2];
        temp += input[i + 3];
        
        output += convertBinToHex(temp);
        temp = "";
    }
    
    return output;
}

int findInSymTab(vector<string> symtab, vector<int> symloc, string element) {
    for(int i = 0; i < symtab.size(); i++) {
        if(symtab.at(i) == element) {
            return symloc.at(i);
        }
    }
}


//This Function Generates Object Codes Based on Certain Parameters
string getObjCode(string opcode, string operand, vector<string> symtab,vector<int> symloc, vector<string> opcodes, vector<string> opcodesHex, int l, vector<string> locctrs_strings) {
    bool isFormat4 = false;
    if(opcode[0] == '+') {
        isFormat4 = true;
        opcode.replace(0,1,"");
    }
    
    
    if(contains(opcodes, opcode)) {
        string opInBin = "";
        char nixbpe[6];
        string output = "";
        
        if (opcode == "RSUB") {
            return "4F0000";
        } else if(opcode == "COMPR") {
            return "A004";
        } else if(opcode == "CLEAR") {
            if(operand == "X") {
                return "B410";
            }
            if(operand == "A") {
                return "B400";
            }
            if(operand == "S") {
                return "B440";
            }
        } else if(operand[0] == '@') {
            return "3E2003";
        } else {
            int key = findElement(opcodes, opcode);
            string ocInBin = opcodesHex.at(key);
            ocInBin = hexaToBin(ocInBin);
            ocInBin = ocInBin.substr(0, ocInBin.size()-1);
            ocInBin = ocInBin.substr(0, ocInBin.size()-1);
            if(isFormat4) {
                if(operand[0] == '#') {
                    nixbpe[0] = '0';
                    nixbpe[1] = '1';
                    nixbpe[2] = '0';
                    nixbpe[3] = '0';
                    nixbpe[4] = '0';
                    nixbpe[5] = '1';
                    string opAddress = "01000";
                    
                    // cout << opAddress << endl;
                    // opAddress = hexaToBin(opAddress);
                    
                    output = ocInBin + nixbpe;
                    return transformToHexa(output) + opAddress;
                } else {
                    nixbpe[0] = '1';
                    nixbpe[1] = '1';
                    nixbpe[2] = '0';
                    nixbpe[3] = '0';
                    nixbpe[4] = '0';
                    nixbpe[5] = '1';
                    string opAddress = fillBits(decimalToHexa(findInSymTab(symtab, symloc, operand)), 5);

                    
                    output = ocInBin + nixbpe;
                    return transformToHexa(output) + opAddress;
                }
            } else {
                if(operand[0] == '#') {
                    if(operand[1] == '0' || operand[1] == '3') {
                        nixbpe[0] = '0';
                        nixbpe[1] = '1';
                        nixbpe[2] = '0';
                        nixbpe[3] = '0';
                        nixbpe[4] = '0';
                        nixbpe[5] = '0';
                        string opAddress = "00" + operand[1];
                        
                        output = ocInBin + nixbpe;
                        return transformToHexa(output) + "00" + operand[1];
                    }
                    
                    nixbpe[0] = '0';
                    nixbpe[1] = '1';
                    nixbpe[2] = '0';
                    nixbpe[5] = '0';
                    
                    int disp = hexaToDecimal(decimalToHexa(findInSymTab(symtab, symloc, operand))) - hexaToDecimal(findPC(l, locctrs_strings));
                    string dispHex;
                    
                    if(disp > -2048 && disp < 2048) {
                        dispHex = decimalToHexa(disp);
                        nixbpe[3] = '0';
                        nixbpe[4] = '1';
                    } else {
                        disp = hexaToDecimal(decimalToHexa(findInSymTab(symtab, symloc, operand))) - hexaToDecimal(findBase());
                        dispHex = decimalToHexa(disp);
                        nixbpe[3] = '1';
                        nixbpe[4] = '0';
                    }
                    
                    if(dispHex.size() > 3) {
                        dispHex = dispHex.substr( dispHex.length() - 3);
                    } else if(dispHex.length() < 3) {
                        dispHex = fillBits(dispHex, 3);
                    }
                    
                    output = ocInBin + nixbpe;
                    return transformToHexa(output) + dispHex;
                    
                } else {
                    nixbpe[5] = '0';
                    if (operand.find(",X") != std::string::npos) {
                        nixbpe[2] = '1';
                        operand = operand.substr(0, operand.size()-1);
                        operand = operand.substr(0, operand.size()-1);
                    } else {
                        nixbpe[2] = '0';
                    }
                    
                    nixbpe[0] = '1';
                    nixbpe[1] = '1';
                    
                    // cout << "opAddress: " << decimalToHexa(findInSymTab(symtab, symloc, operand)) << endl;
                    // cout << "PC: " << findPC(l, locctrs_strings) << endl;
                    // cout << "opA in hexa" << hexaToDecimal(decimalToHexa(findInSymTab(symtab, symloc, operand))) << endl;
                    // cout << "PC in hexa" << hexaToDecimal(findPC(l, locctrs_strings)) << endl;
                    int disp = hexaToDecimal(decimalToHexa(findInSymTab(symtab, symloc, operand))) - hexaToDecimal(findPC(l, locctrs_strings));
                    // cout << disp << endl;
                    string dispHex;
                    
                    if(disp > -2048 && disp < 2048) {
                        dispHex = decimalToHexa(disp);
                        nixbpe[3] = '0';
                        nixbpe[4] = '1';
                    } else {
                        disp = hexaToDecimal(decimalToHexa(findInSymTab(symtab, symloc, operand))) - hexaToDecimal(findBase());
                        dispHex = decimalToHexa(disp);
                        nixbpe[3] = '1';
                        nixbpe[4] = '0';
                    }
                    
                    if(dispHex.size() > 3) {
                        dispHex = dispHex.substr( dispHex.length() - 3);
                    } else if(dispHex.length() < 3) {
                        dispHex = fillBits(dispHex, 3);
                    }
                    
                    //cout << dispHex << endl;
                    
                    // cout << nixbpe << endl;
                    //cout << disp << endl;
                    //dispHex = fillBits(dispHex, 3);
                    //cout << dispHex << endl;
                    output = ocInBin + nixbpe;
                    return transformToHexa(output) + dispHex;
                }
            }
        }
        
    } else {
        
        int isIndexed = false;
        
        if(opcode == "WORD") {
            string output = decimalToHexa(stoi(operand));
            while(output.length() != 6) {
                output.insert(0, "0");
            }
            return output;
        }
        
        if(opcode == "BYTE") {
            string str = operand;
            if(str[0] == 'X') {
                str.erase(0, 2);
                str.pop_back();
                return str;
            }
            
            if(str[0] == 'C') {
                str.erase(0, 2);
                str.pop_back();
                return str;
            }
        }
        
        if (operand.find(",X") != std::string::npos) {
            isIndexed = true;
            operand = operand.substr(0, operand.size()-1);
            operand = operand.substr(0, operand.size()-1);
        }
        
        int key = findElement(opcodes, opcode);
        string output = opcodesHex.at(key);
        
        int keyOfSym = findElement(symtab, operand);
        int address = symloc.at(keyOfSym);
        
        if(isIndexed) {
            address += hexaToDecimal("8000");
        }
        
        output += decimalToHexa(address);
        
        
        return  output;
    }
}

int main()
{
    int locctr;
    int startAddress;
    int programLength;
    int ctr = 0;
    string currentOp;
    string programName;
    
    vector<string> symtab;
    vector<string> opcodes;
    vector<string> opcodesHex;
    vector<int> symloc;
    vector<int> locctrs;
    vector<string> locctrs_strings;
    
    vector<string> lines;
    vector<string> symbols;
    vector<string> opcode;
    vector<string> operand;

    string input;

    ifstream codeFile("inSICXE.txt");
    vector<string> v;
    
    opcodes.push_back("LDA");
    opcodesHex.push_back("00");
    
    opcodes.push_back("STL");
    opcodesHex.push_back("14");
    
    opcodes.push_back("JSUB");
    opcodesHex.push_back("48");
    
    opcodes.push_back("LDB");
    opcodesHex.push_back("68");
    
    opcodes.push_back("COMP");
    opcodesHex.push_back("28");
    
    opcodes.push_back("JEQ");
    opcodesHex.push_back("30");
    
    opcodes.push_back("J");
    opcodesHex.push_back("3C");
    
    opcodes.push_back("STA");
    opcodesHex.push_back("0C");
    
    opcodes.push_back("CLEAR");
    opcodesHex.push_back("B4");
    
    opcodes.push_back("LDT");
    opcodesHex.push_back("74");
    
    opcodes.push_back("TD");
    opcodesHex.push_back("E0");
    
    opcodes.push_back("RD");
    opcodesHex.push_back("D8");
    
    opcodes.push_back("COMPR");
    opcodesHex.push_back("A0");
    
    opcodes.push_back("TIXR");
    opcodesHex.push_back("B8");
    
    opcodes.push_back("STX");
    opcodesHex.push_back("10");
    
    opcodes.push_back("RSUB");
    opcodesHex.push_back("4C");
    
    opcodes.push_back("WD");
    opcodesHex.push_back("DC");
    
    opcodes.push_back("LDCH");
    opcodesHex.push_back("50");
    
    opcodes.push_back("STCH");
    opcodesHex.push_back("54");
    
    opcodes.push_back("JLT");
    opcodesHex.push_back("38");

    while(getline(codeFile, input)) {
        lines.push_back(trim(std::regex_replace(input, space_re, " ")));
    }
    
    for(int i = 0; i < lines.size(); i++) {
        vector<string> strings = split(lines.at(i), " ");
        
        if(strings.size() == 3) {
            symbols.push_back(strings.at(0));
            opcode.push_back(strings.at(1));
            operand.push_back(strings.at(2));
        }
        else if(strings.size() == 2) {
            symbols.push_back("x");
            opcode.push_back(strings.at(0));
            operand.push_back(strings.at(1));
        } else if(strings.size() == 1) {
            symbols.push_back("x");
            opcode.push_back(strings.at(0));
            operand.push_back("y");
        }
    }
    
    if(opcode.at(0) == "START") {
            locctr = stoi(operand.at(0));
            startAddress = locctr;
            ctr++;
    } else {
        locctr = 0;
        startAddress = 0;
    }
    
    startAddress = hexaToDecimal(to_string(startAddress));
    locctr = startAddress;
    
    while(currentOp != "END") {
        currentOp = opcode.at(ctr);
        
        if(symbols.at(ctr) != "x") {
            bool errorFlag = true;
            for(int i = 0; i < symtab.size(); i++) {
                if(symbols.at(ctr) == symtab.at(i)) {
                    errorFlag = false;
                }
            }
            if(errorFlag == true) {
                symtab.push_back(symbols.at(ctr));
                symloc.push_back(locctr);
            }
        }
        
        if(opcode.at(ctr) != "WORD" && opcode.at(ctr) != "RESW" && opcode.at(ctr) != "BYTE" && opcode.at(ctr) != "RESB" && opcode.at(ctr) != "BASE" && opcode.at(ctr)[0] != '+' && opcode.at(ctr) != "CLEAR" && opcode.at(ctr) != "COMPR" && opcode.at(ctr) != "TIXR") {
            locctr += 3;
        } else if(opcode.at(ctr) != "WORD" && opcode.at(ctr) != "RESW" && opcode.at(ctr) != "BYTE" && opcode.at(ctr) != "RESB" && opcode.at(ctr)[0] == '+' && opcode.at(ctr) != "BASE" && opcode.at(ctr) != "CLEAR" && opcode.at(ctr) != "COMPR" && opcode.at(ctr) != "TIXR") {
            locctr += 4;
        } else if(opcode.at(ctr) == "BASE") {
            locctr += 0;
        } else if(opcode.at(ctr) == "CLEAR" || opcode.at(ctr) == "COMPR" || opcode.at(ctr) == "TIXR") {
            locctr += 2;
        } else if(currentOp == "WORD") {
            locctr += 3;
        } else if(currentOp == "RESW") {
            locctr += 3 * stoi(operand.at(ctr));
        } else if(currentOp == "RESB") {
            locctr += stoi(operand.at(ctr));
        } else if(currentOp == "BYTE") {
            string str = operand.at(ctr);
            int length;
            
            if(str[0] == 'X') {
                str.erase(0, 2);
                str.pop_back();
                length = str.size();
                locctr += length/2;
            } else if(str[0] == 'C') {
                str.erase(0, 2);
                str.pop_back();
                length = str.size();
                locctr += length;
            }
        }
        
        ctr++;
        locctrs.push_back(locctr);
    }

    locctrs.insert(locctrs.begin(), startAddress);
    
    for(int i = 0; i < locctrs.size(); i++) {
        locctrs_strings.push_back(decimalToHexa(locctrs.at(i)));
    }
    
    programLength = locctr - startAddress;

    
    programName = symbols.at(0);
    
    opcode.erase(opcode.begin());
    operand.erase(operand.begin());
    symbols.erase(symbols.begin());
    
    cout << "===== LOCATION COUNTERS  =====" << endl;

    for(int i = 0; i < opcode.size(); i++) {
        if(opcode.at(i) != "BASE") {
            cout << locctrs_strings.at(i)  << " " << symbols.at(i) << " " << opcode.at(i) << " " << operand.at(i) << " " << getObjCode(opcode.at(i), operand.at(i), symtab, symloc, opcodes, opcodesHex, i, locctrs_strings) << endl;
        }
    }
    
    cout << "\n\n===== SYMBOL TABLE  =====" << endl;
    
    for(int i = 0; i < symtab.size(); i++) {
        cout << symtab.at(i) << " " << decimalToHexa(symloc.at(i)) << endl;
    }
    
        cout << "\n\n===== HTE RECORDS =====" << endl;
    
    string lengthInBits = to_string(locctrs.at(locctrs.size() - 2) - startAddress);
    while(lengthInBits.length() != 6) {
        lengthInBits.insert(0, "0");
    }
    string startInBits = to_string(startAddress);
    while(startInBits.length() != 6) {
        startInBits.insert(0, "0");
    }
    
    vector<string> tRecCodes;
    string current = "";
    
    //H Record
    cout << "H. " << programName << ". " << lengthInBits << endl;
    
    //T Records
    int x = 0;
    int y = -1;
    vector<int> start;
    vector<string> temp;
    vector<int> length;
    
    while(x < opcode.size()) {

        if(opcode.at(x) != "RESW" && opcode.at(x) != "RESB") {
            start.push_back(locctrs.at(x));
            temp.push_back("");
            tRecCodes.push_back("");
            y++;
        }
        
        for(int j = 0; j < 10; j++) {
            if(opcode.at(x) != "RESW" && opcode.at(x) != "RESB" && opcode.at(x) != "END") {
                tRecCodes.at(y) += getObjCode(opcode.at(x), operand.at(x), symtab,symloc,opcodes, opcodesHex, x, locctrs_strings) + " ";
                current = opcode.at(x);
                x++;
                temp.at(y) = to_string(locctrs.at(x)) + " ";
            } else {
                current = opcode.at(x);
                x++;
                break;
            }
        }
        
        
        if(current == "END") {
            break;
        }
    }
    
    for(int i = 0; i < tRecCodes.size(); i++) {
        length.push_back(stoi(temp.at(i)) - start.at(i));
    }
    
    for(int i = 0; i < tRecCodes.size(); i++) {
        cout << "T. " << fillBits(decimalToHexa(start.at(i)), 6)  << ". " << fillBits(to_string(length.at(i)), 2) << ". " << tRecCodes.at(i) << endl;
    }
    
    //E Records
    cout << "E. " << fillBits(decimalToHexa(stoi(startInBits)), 6) << endl;
    
    //cout << transformToHexa("0101010101111100") << endl;
    
    return 0;
}