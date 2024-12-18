#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

const int MAX_HISTORY = 100;
const int MAX_CUSTOM_UNITS = 50;

string conversionHistory[MAX_HISTORY];
int historyCount = 0;

string customUnitNames[MAX_CUSTOM_UNITS];
double customUnitFactors[MAX_CUSTOM_UNITS];
int customUnitCount = 0;

void lengthConverter();
void weightConverter();
void temperatureConverter();
void volumeConverter();
void timeConverter();
void saveToHistory(const string &entry);
void viewHistory();
void saveResultsToFile(const string &result);
void addCustomUnit();
void searchUnits();

int main()
{
    int choice;
    do
    {
        cout << endl << "=== Unit Converter ===" << endl;
        cout << "1. Length Conversion" << endl;
        cout << "2. Weight Conversion" << endl;
        cout << "3. Temperature Conversion" << endl;
        cout << "4. Volume Conversion" << endl;
        cout << "5. Time Conversion" << endl;
        cout << "6. View Conversion History" << endl;
        cout << "7. Add Custom Unit" << endl;
        cout << "8. Search Custom Units" << endl;
        cout << "9. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Please enter a number" << endl;
            continue;
        }

        switch (choice)
        {
            case 1: lengthConverter(); break;
            case 2: weightConverter(); break;
            case 3: temperatureConverter(); break;
            case 4: volumeConverter(); break;
            case 5: timeConverter(); break;
            case 6: viewHistory(); break;
            case 7: addCustomUnit(); break;
            case 8: searchUnits(); break;
            case 9: cout << "Exiting" << endl;
                break;
            default: cout << "Try again" << endl;
        }
    } while (choice != 9);

    return 0;
}

void saveToHistory(const string &entry)
{
    if (historyCount < MAX_HISTORY)
    {
        conversionHistory[historyCount++] = entry;
    }
    
    else
    {
        cout << "History is full" << endl;
    }
}

void viewHistory()
{
    cout << endl << "--- Conversion History ---" << endl;
    if (historyCount == 0)
    {
        cout << "No conversion history" << endl;
    }
    else
    {
        for (int i = 0; i < historyCount; i++)
        {
            cout << i + 1 << ". " << conversionHistory[i] << endl;
        }
    }
}

void saveResultsToFile(const string &result)
{
    ofstream outFile("conversionResults.txt", ios::app);
    if (outFile)
    {
        outFile << result << endl;
        outFile.close();
        cout << "Result saved to file" << endl;
    }
    else
    {
        cout << "Error saving to file" << endl;
    }
}

void lengthConverter()
{
    double value;
    int choice;

    cout << endl << "--- Length Converter ---" << endl;
    cout << "1. Meters to Kilometers" << endl;
    cout << "2. Kilometers to Miles" << endl;
    cout << "3. Feet to Inches" << endl;
    cout << "4. Inches to Centimeters" << endl;
    cout << "5. Miles to Kilometers" << endl;

    cout << "Enter your choice: ";
    cin >> choice;
    cout << "Enter value: ";
    cin >> value;

    string result;
    switch (choice)
    {
        case 1: result = to_string(value) + " meters = " + to_string(value / 1000) + " kilometers"; break;
        case 2: result = to_string(value) + " kilometers = " + to_string(value * 0.621371) + " miles"; break;
        case 3: result = to_string(value) + " feet = " + to_string(value * 12) + " inches"; break;
        case 4: result = to_string(value) + " inches = " + to_string(value * 2.54) + " centimeters"; break;
        case 5: result = to_string(value) + " miles = " + to_string(value * 1.60934) + " kilometers"; break;
        default: result = "Invalid choice";
    }

    cout << result << endl;
    saveToHistory(result);
    saveResultsToFile(result);
}

void weightConverter()
{
    double value;
    int choice;

    cout << endl << "--- Weight Converter ---" << endl;
    cout << "1. Kilograms to Grams" << endl;
    cout << "2. Kilograms to Pounds" << endl;
    cout << "3. Pounds to Ounces" << endl;
    cout << "4. Ounces to Grams" << endl;

    cout << "Enter your choice: ";
    cin >> choice;
    cout << "Enter value: ";
    cin >> value;

    string result;
    switch (choice)
    {
        case 1: result = to_string(value) + " kilograms = " + to_string(value * 1000) + " grams"; break;
        case 2: result = to_string(value) + " kilograms = " + to_string(value * 2.20462) + " pounds"; break;
        case 3: result = to_string(value) + " pounds = " + to_string(value * 16) + " ounces"; break;
        case 4: result = to_string(value) + " ounces = " + to_string(value * 28.3495) + " grams"; break;
        default: result = "Invalid choice";
    }

    cout << result << endl;
    saveToHistory(result);
    saveResultsToFile(result);
}

void temperatureConverter()
{
    double value;
    int choice;

    cout << endl << "--- Temperature Converter ---" << endl;
    cout << "1. Celsius to Fahrenheit" << endl;
    cout << "2. Fahrenheit to Celsius" << endl;
    cout << "3. Celsius to Kelvin" << endl;

    cout << "Enter your choice: ";
    cin >> choice;
    cout << "Enter temperature value: ";
    cin >> value;

    string result;
    switch (choice)
    {
        case 1: result = to_string(value) + " °C = " + to_string((value * 9 / 5) + 32) + " °F"; break;
        case 2: result = to_string(value) + " °F = " + to_string((value - 32) * 5 / 9) + " °C"; break;
        case 3: result = to_string(value) + " °C = " + to_string(value + 273.15) + " K"; break;
        default: result = "Invalid choice";
    }

    cout << result << endl;
    saveToHistory(result);
    saveResultsToFile(result);
}

void volumeConverter()
{
    double value;
    int choice;

    cout << endl << "--- Volume Converter ---" << endl;
    cout << "1. Liters to Milliliters" << endl;
    cout << "2. Liters to Gallons" << endl;
    cout << "3. Gallons to Cups" << endl;

    cout << "Enter your choice: ";
    cin >> choice;
    cout << "Enter value: ";
    cin >> value;

    string result;
    switch (choice)
    {
        case 1: result = to_string(value) + " liters = " + to_string(value * 1000) + " milliliters"; break;
        case 2: result = to_string(value) + " liters = " + to_string(value * 0.264172) + " gallons"; break;
        case 3: result = to_string(value) + " gallons = " + to_string(value * 16) + " cups"; break;
        default: result = "Invalid choice";
    }

    cout << result << endl;
    saveToHistory(result);
    saveResultsToFile(result);
}

void timeConverter()
{
    double value;
    int choice;

    cout << endl << "--- Time Converter ---" << endl;
    cout << "1. Seconds to Minutes" << endl;
    cout << "2. Minutes to Hours" << endl;
    cout << "3. Hours to Days" << endl;

    cout << "Enter your choice: ";
    cin >> choice;
    cout << "Enter value: ";
    cin >> value;

    string result;
    switch (choice)
    {
        case 1: result = to_string(value) + " seconds = " + to_string(value / 60) + " minutes"; break;
        case 2: result = to_string(value) + " minutes = " + to_string(value / 60) + " hours"; break;
        case 3: result = to_string(value) + " hours = " + to_string(value / 24) + " days"; break;
        default: result = "Invalid choice";
    }

    cout << result << endl;
    saveToHistory(result);
    saveResultsToFile(result);
}

void addCustomUnit()
{
    if (customUnitCount >= MAX_CUSTOM_UNITS)
    {
        cout << "Custom unit list is full" << endl;
        return;
    }

    cout << endl << "--- Add Custom Unit ---" << endl;
    cout << "Enter unit name: ";
    cin >> customUnitNames[customUnitCount];

    cout << "Enter conversion factor: ";
    cin >> customUnitFactors[customUnitCount];

    cout << "Custom unit added" << endl;
    customUnitCount++;
}

void searchUnits()
{
    string search;
    cout << endl << "Enter unit name to search: ";
    cin >> search;

    bool found = false;
    for (int i = 0; i < customUnitCount; i++)
    {
        if (customUnitNames[i] == search)
        {
            cout << "Unit found: " << customUnitNames[i] << ", Factor: " << customUnitFactors[i] << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Unit not found" << endl;
    }
}
