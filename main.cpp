/**********************************************************************************************************************
 // FileName:        main.c
 // Program version: Dev-C++ 5.11
 // Company:         TECNM - ITCH
 // Description:     ADC!!!
 // Authors:         Mario Alejandro Briones Lara
 // Updated:         xx/2023
 //Nota:			 Lab_3
************************************************************************************************************************/
 #include <stdlib.h>
 #include <iostream>
 #include <math.h>
 using namespace std;
//**********************************************************************************************************************
 class ADC{
 	int _res;			//Resolución (8, 10 o 12 bits)
 	int _freq;			//Frecuencia de muestreo
 	int _num_can;		//Cantidad de canales a leer
 	int _can_an[32];	//Definir cuales canales se va a leer (los canales son AN1, …, AN32)
 public:
	ADC(int _res,int _freq,int _num_can,int _can_an[]);
	void setup();
	int setData(int canal);
	void getData();
 };
//**********************************************************************************************************************
 ADC::ADC(int res,int freq,int num_can,int can_an[]){
 	_res = res;
 	_freq = freq;
 	_num_can = num_can;
 	for(int i = 0; i < num_can ;i++){
 		_can_an[i] = can_an[i];
	}
 }
//**********************************************************************************************************************
 void ADC::setup(){
	cout << "Configuracion del ADC:" << endl;
    cout << "Resolucion (8, 10, or 12 bits): ";
    cin >> _res;
    while(_res !=8 && _res !=10 && _res !=12 ){ 
			cout << "Resolucion (8, 10, or 12 bits): ";
    		cin >> _res;
		}
	cout << "Frecuencia de muestreo: ";
    cin >> _freq;
    cout << "Cantidad de canales a leer(AN1-AN32): ";
    cin >> _num_can;
    while(_num_can <1 || _num_can>32){
    	cout << "Cantidad de canales a leer(AN1-AN32): ";
    	cin >> _num_can;
		}
    cout << "Definir cuales canales se va a leer (AN1-AN32): ";
    for (int i = 0; i < _num_can; i++) {
    	cin >> _can_an[i];
    }
 }
//**********************************************************************************************************************
 int ADC::setData(int canal){
 	cout << "Ingrese el voltaje del canal " << canal << " (0-3.3V): ";
    double volt;
    cin >> volt;
    int adcout = volt / (3.3 / pow(2, _res));
    return adcout;
 }
//**********************************************************************************************************************
 void ADC::getData(){
 	cout << "Lecturas ADC:" << endl;
    for (int i = 0; i < _num_can; i++) {
        int canal = _can_an[i];
        int adcout = setData(canal);
    	cout << "Canal " << canal << ": " << adcout << endl;
    }
 }
//**********************************************************************************************************************
 int main() {
 	int canales[]={0};
 	ADC adc(0, 0, 0, canales);
 	adc.setup();
 	adc.getData();
    return 0;
 }
