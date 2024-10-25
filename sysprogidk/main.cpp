#include <iostream>
#include <vector>
using namespace std;


int maxInt(const vector<int>& nums) {
    int max = nums[0];
    for (size_t i = 1; i < nums.size(); i++) {
        if (max < nums[i]) {
            max = nums[i];
        }
    }
    return max;
}

int minInt(const vector<int>& nums) {
    int min = nums[0];
    for (size_t i = 1; i < nums.size(); i++) {
        if (min > nums[i]) {
            min = nums[i];
        }
    }
    return min;
}


float avgFloat(const vector<int>& nums) {
    float sum = 0;
    for (size_t i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }

    return sum / nums.size(); 
}

int sum(vector<int> nums){
    int sum = 0;

    for (int i = 0; i < nums.size(); i++) {
        sum = sum + nums[i];
    }

    return sum; 
}


void verboseNumberString() {
    setlocale(LC_ALL, "");
    string one[] = { "", "один", "два", "три", "четыре", "пять", "шесть", "семь", "восемь", "девять" };
    string ten[] = { "", "десять", "двадцать", "тридцать", "сорок", "пятьдесят", "шестьдесят", "семьдесят", "восемьдесят", "девяносто" };
    string other[] = { "десять", "одиннадцать", "двенадцать", "тринадцать", "четырнадцать", "пятнадцать", "шестнадцать", "семнадцать", "восемнадцать", "девятнадцать" };
    string hundred[] = { "", "сто", "двести", "триста", "четыреста", "пятьсот", "шестьсот", "семьсот", "восемьсот", "девятьсот" };
    string thousand[] = { "", "тысяча", "две тысячи", "три тысячи", "четыре тысячи", "пять тысяч", "шесть тысяч", "семь тысяч", "восемь тысяч", "девять тысяч" };

    int number;
    cout << "Введите число от 0 до 9999: ";
    cin >> number;

    if (number < 0 || number > 9999) {
        cout << "Число должно быть в пределах от 0 до 9999" << endl;
    } else {
        string result = "";

        if (number == 0) {
            cout << "ноль" << endl;
            return;
        }

        if (number / 1000 > 0) {
            result += thousand[number / 1000] + " ";
            number %= 1000;
        }

        if (number / 100 > 0) {
            result += hundred[number / 100] + " ";
            number %= 100;
        }

        if (number / 10 == 1) {
            result += other[number % 10] + " ";
        } else {
            if (number / 10 > 0) {
                result += ten[number / 10] + " ";
            }
            number %= 10;

            if (number > 0) {
                result += one[number] + " ";
            }
        }

        cout << result << endl;
    }
}


void getFingerName() {
    setlocale(LC_ALL, "");
    int num;
    cout << "Введите номер пальца: ";
    cin >> num;
    switch (num) {
        case 1: cout << "Большой палец"; break;
        case 2: cout << "Указательный палец"; break;
        case 3: cout << "Средний палец"; break;
        case 4: cout << "Безымянный палец"; break;
        case 5: cout << "Мизинец"; break;
        default: cout << "Введите номер от 1 до 5" << endl;
    }
}

void isCorrectMulti() {
    setlocale(LC_ALL, "");
    int a, b, result;
    cout << "Введите a: ";
    cin >> a;
    cout << "Введите b: ";
    cin >> b;
    cout << "Введите результат: ";
    cin >> result;

    if (a * b == result) {
        cout << "Правильный ответ!" << endl;
    } else {
        cout << "Неправильный ответ!" << endl;
    }
}


void getSchedule() {
    string monday = "15:00 - 16:20 Практическая и лабораторная работа по программированию\n16:30 - 17:50 Конструирование ПИ";
    string tuesday = "13:00 - 14:20 Web-программирование\n15:00 - 16:20 Конструирование ПИ\n16:30 - 17:50 Практическая и лабораторная работа по программированию";
    string wednesday = "13:00 - 14:20 Web-программирование\n15:00 - 16:20 Граф практической работы\n16:30 - 17:50 Граф практической работы";
    string thursday = "Выходной";
    string friday = "13:30 - 14:20 Смешанное программирование\n15:00 - 16:20 Смешанное программирование";
    string saturday = "Выходной";
    string sunday = "11:30 - 12:50 Дашборд с работой\n13:00 - 14:20 - Дашборд с работой";

    int dayNum;
    cout << "Введите номер дня недели: ";
    cin >> dayNum;

    switch (dayNum) {
        case 1: cout << monday; break;
        case 2: cout << tuesday; break;
        case 3: cout << wednesday; break;
        case 4: cout << thursday; break;
        case 5: cout << friday; break;
        case 6: cout << saturday; break;
        case 7: cout << sunday; break;
        default: cout << "Введите номер от 1 до 7" << endl; break;
    }
}


void letterManagement() {
    char letter;
    cout << "Введите букву: ";
    cin >> letter;
    char upperLetter = toupper(letter);
    cout << "Эта буква " << upperLetter << ", не забудьте о регистре" << endl;
}


void squares() {
    vector<int> nums;

    while (true) {
        int num;
        cout << "Введите число: (или введите '0' чтобы выйти из режима): ";
        cin >> num;

        if (num == 0) {
            cout << "Выход из режима." << endl;
            break;
        }
        cout << "Квадрат от " << num << " = " << num * num << endl;
    }
}


void enterGym() {
    int peopleCount = 0;
    vector<int> ages;

    while (true) {
        int currentAge;
        cout << "Введите возраст участника, введите '0' чтобы закончить ввод: ";
        cin >> currentAge;

        if (currentAge == 0) {
            break;
        }
        peopleCount++;
        ages.push_back(currentAge);
    }

    if (peopleCount == 0) {
        cout << "Нет данных для вывода" << endl;
        return;
    }

    int max = maxInt(ages);
    int min = minInt(ages);
    float avg = avgFloat(ages);

    cout << "\nОбщее количество участников - " << peopleCount << endl;
    cout << "Максимальный возраст участника - " << max << endl;
    cout << "Минимальный возраст участника - " << min << endl;
    cout << "Средний возраст участников - " << avg << endl;
}


void numsInfo(){
    vector<int> nums;
    int count = 0;

    while (true){
        int currentNum;
        cout << "Введите текущее число (или 0 что бы выйти из программы) - ";
        cin >> currentNum;
        if (currentNum == 0){
            break;
        }
        nums.push_back(currentNum);
        count ++;
    }

    int summa = sum(nums);
    int avg = avgFloat(nums);
    cout << "Кол-во чисел - " << count << "\n";
    cout << "Сумма чисел - " << sum(nums) << "\n";
    cout << "Ср арифметическое чисел - " << avgFloat(nums) << "\n";
}


void oddSum(){
    vector<int> nums;

    while(true){
        int currentNum;
        cout << "Введите число или 0 для выхода из программы - ";
        cin >> currentNum;

        if(currentNum == 0){
            break;
        }
        nums.push_back(currentNum);
    }

    int sum = 0;
    for (int i = 0; i < nums.size(); i++){
        if (nums[i]%2 != 0){
            sum += nums[i];
        }
    }
    
    cout << "Сумма нечетных чисел - " << sum << "\n";
}


void drawTriangle(){
    int height;
    cout << "Введите высоту треугольника - ";
    cin >> height;

    for (int i = 0; i < height+1; i++){
        int count = 0;

        while(count < i){
            cout << "^ ";
            count++;
        }

        cout << "\n";
    }
}


int main() {
    setlocale(LC_ALL, "");
    // ВЫЗОВЕШЬ ЗДЕСЬ НУЖНУЮ ФУНКЦИЮ (ЛАБУ)

    return 0;
}
