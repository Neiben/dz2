// hw2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int priority(string str) {
    int tmp;
    if ((str == "+") || (str == "-")) {
        tmp = 1;
        return tmp;
    }
    if ((str == "*") || (str == "/")) {
        tmp = 2;
        return tmp;
    }
}


bool op(string str) {
    bool tmp;
    if (str == "+") {
        tmp = true;
        return tmp;
    }
    if (str == "-") {
        tmp = true;
        return tmp;
    }
    if (str == "*") {
        tmp = true;
        return tmp;
    }
    if (str == "/") {
        tmp = true;
        return tmp;
    }
    else {
        tmp = false;
        return tmp;
    }
    
}


string calculate(string a, string b, string op) {
    double A = stod(a);
    double B = stod(b);
    double C;
    vector<double> result;
    if (op == "+") {
      C = A + B;
      to_string(C);
      return to_string(C);
    }
    if (op == "-") {
        C = A - B;
        to_string(C);
        return to_string(C);
    }
    if (op == "*") {
        C = A * B;
        to_string(C);
        return to_string(C);
    }
    if (op == "/") {
        C = A + B;
        to_string(C);
        return to_string(C);
    }
}

int main()
{
    string expression;
    cout << " enter your expression: ";
    cin >> expression;
    vector <string> result;
    vector<string>operations;
    string tmp;
    string abc = " ";
    char dot = '.';
    bool check;
    for (int i = 0; i < expression.length(); i++) {
        tmp += expression[i];
        if (isdigit(expression[i])) {
            result.push_back(tmp);            
            tmp = "";           
        }
        else if (tmp == ".") {
            result.push_back(tmp);
            tmp = "";
        }
        /*else if (isdigit(expression[i]) && (expression[i-1] == dot)) {
            result.push_back(tmp);
            result.push_back(abc);
            tmp = "";
        }*/
        else if (op(tmp)) {
            if ((operations.empty()) || (operations.back() == "("))
            {
                result.push_back(abc);
                operations.push_back(tmp);
                tmp = "";
            }          
            else if (priority(operations.back()) < priority(tmp))
            {
                result.push_back(abc);
                operations.push_back(tmp); 
                tmp = "";
            }
            else if (priority(operations.back()) >= priority(tmp)) {
                while ((!operations.empty())&& ((priority(operations.back()) >= priority(tmp)) && (operations.back() != "(")))
                {
                    result.push_back(operations.back());
                    operations.pop_back();                   
                }
                result.push_back(abc);
                operations.push_back(tmp);   
                tmp = "";
            }
                     
        }
        else if (tmp == "(") {
            operations.push_back(tmp);
            tmp = "";
        }
        else if (tmp == ")") {
            while ((operations.back() != "(") && (!operations.empty())) {
                result.push_back(operations.back());
                operations.pop_back();
            }
            tmp = "";
        }
    }
   
    while (!operations.empty()) {
        result.push_back(operations.back());
        operations.pop_back();
    }
    string tmp2;
    tmp2 = result.back();
    if (tmp2 == "(") {
        result.pop_back();
    }
    for (int i = 0; i < result.size(); i++) {
        if (result[i] == "(")
        {
            result.erase(result.begin() + i);           
        }
    }
    string tr_rez;                              
    for (int i = 0; i < result.size(); i++) {
         tr_rez += result[i];                       
    }
    cout <<"your expression written through RPN : "<< tr_rez;                             



   // start calculating
    vector<string> answer;
    string tmp3;
    string separator = " ";
    for (int i = 0; i < tr_rez.size(); i++) {
        tmp3 += tr_rez[i];
        if (isdigit(tr_rez[i])) {
            while (tr_rez[i] != ' ') {
                answer.push_back(tmp3);
            }           
        }
        if (tmp3 == abc) {
            answer.push_back(abc);
            tmp3 = "";
        }

        else if (op(tmp3)) {
            for (int i = 0; i < answer.size(); i++) {
                string A = answer.back();
                answer.pop_back();
                if (answer.back() == " ") {
                    answer.pop_back();
                }
                string B = answer.back();
                answer.pop_back();
                answer.push_back(calculate(B, A, tmp3));

                tmp3 = "";
            }
        }
    }
    cout << endl << " your answer is : " << answer.back();













       /* tmp3 += tr_rez[i];
        if (isdigit(tr_rez[i])) {
            answer.push_back(tmp3);
            tmp3 = "";
        }
        else if (tr_rez[i] == dot) {
            answer.push_back(tmp3);
            tmp3 = "";
        }
        else if (tmp3 == abc) {
            answer.push_back(tmp3);
            tmp3 = "";
        }
        else if (op(tmp3)) {
            string A = answer.back();
            answer.pop_back();
            if (answer.back() == " ") {
                answer.pop_back();
            }
            string B = answer.back();
            answer.pop_back();
            answer.push_back(calculate(B, A, tmp3));
           
            tmp3 = "";
        }
    }
    cout << endl <<" your answer is : " << answer.back();*/
}
    



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
