﻿// hw2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
        C = A / B;
        to_string(C);
        return to_string(C);
    }
}

int main()
{
    string expression;
    std::cout << " enter your expression: ";
    cin >> expression;
    vector <string> result;
    vector<string>operations;
    string tmp;
    string abc = " ";
    string dot = ".";
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
                while ((!operations.empty()) && ((priority(operations.back()) >= priority(tmp)) && (operations.back() != "(")))
                {
                    result.push_back(abc);
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
                result.push_back(abc);
                result.push_back(operations.back());
                operations.pop_back();
            }
            tmp = "";
        }
    }

    while (!operations.empty()) {
        result.push_back(abc);
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
    if (result.back() == abc) {
        result.pop_back();
    }
    for (int i = 0; i < result.size(); i++) {
        if ((result[i] == " ") && (result[i + 1] == " "))
        {
            result.erase(result.begin() + i);
        }
    }

    string tr_rez;
    for (int i = 0; i < result.size(); i++) {
        tr_rez += result[i];
    }

    std::cout << "your expression written through RPN : " << tr_rez;


    //start calculating
    vector<string> answer;
    string reez2;
    string tmp3;
    string tmp5;
    string tmp4;
    string tmp6;
    string reez;
    string A;
    string G;
    string B;
    for (int i = 0; i < tr_rez.size(); i++) {
        tmp3 += tr_rez[i];
        if (isdigit(tr_rez[i])) {
            answer.push_back(tmp3);
            tmp3 = "";
        }
        else if (tmp3 == ".") {
            answer.push_back(tmp3);
            tmp3 = "";
        }

        else if (tmp3 == abc) {
            answer.push_back(tmp3);
            tmp3 = "";
        }




        else if (op(tmp3)) {
            if (answer.back() == " ") {
                if (!answer.empty()) {
                    answer.pop_back();
                }
           }

            for (int i = 0; i < answer.size(); i++) {
                reez += answer[i];
            }
           
      

            for (int i = reez.size() - 1; i >= 0; i--) {
                tmp4 += reez[i];
                if (isdigit(reez[i])) {
                    A += tmp4;
                    tmp4 = "";
                    if (!answer.empty()) {
                        answer.pop_back();
                    }

                }
                else if (tmp4 == ".") {
                    A += tmp4;
                    tmp4 = "";
                    if (!answer.empty()) {
                        answer.pop_back();
                    }

                }
                else if (op(tmp4)) {
                    A += tmp4;
                    tmp4 = "";
                    if (!answer.empty()) {
                        answer.pop_back();
                    }
                }
                else if (tmp4 == " ") {
                    if ((!answer.empty()) && (answer.back() == " ")) {
                        answer.pop_back();
                        break;
                    }
                }
            }
                    
                    for (int i = 0; i < answer.size(); i++) {
                        reez2 += answer[i];

                    }
                    
                   
                    
              
                    for (int i = reez2.size()-1; i >= 0; i--) {
                        tmp5 += reez2[i];
                        if (isdigit(reez2[i])) {
                            B += tmp5;
                            tmp5 = "";
                            if (!answer.empty()) {
                                answer.pop_back();
                            }

                        }
                        else if (tmp5 == ".") {
                            B += tmp5;
                            tmp5 = "";
                            if (!answer.empty()) {
                                answer.pop_back();
                            }

                        }
                        else if (op(tmp5)) {
                            B += tmp5;
                            tmp5 = "";
                            if (!answer.empty()) {
                                answer.pop_back();
                            }
                        }
                        else if  ((answer.empty()) || (tmp5 == abc))
                        {
                           
                               
                                break;
                            }

                    }   
                   
                
                
               
            
           
          
           
            
           reverse(A.begin(), A.end());
            reverse(B.begin(), B.end());
           /*cout <<endl<< A<< endl;
           cout << B << endl;*/
            answer.push_back(calculate(B, A, tmp3));
            float b = stof(answer.back());
            cout << endl << b;
            cout << endl;
            G = to_string(b);
            cout << G;
           
            for (int i = 0; i < G.size(); i++) {
                if (G.back() == '0') {
                    G.pop_back();
                }
            }
            for (int i = 0; i < G.size(); i++) {
                if (G.back() == '0') {
                    G.pop_back();
                }
            }
            for (int i = 0; i < G.size(); i++) {
                if (G.back() == '.') {
                    G.pop_back();
                }
            }
            cout << endl << G;
            answer.pop_back();
              
            for (int i = 0; i < G.size(); i++) {
                tmp6 += G[i];
                answer.push_back(tmp6);
                tmp6 = "";
            }
            cout << endl;
            for (int i = 0; i < answer.size(); i++) {
                cout << answer[i];
            }
           

            G = "";
            A = "";
            B = "";
            reez = "";
            reez2 = "";
            tmp3 = "";
          
            
        }


       
           
    }
   cout << endl << " your answer is : ";
   for (int i = 0; i < answer.size(); i++) {
       cout << answer[i];
   }

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
