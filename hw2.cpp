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
                        else if  ((answer.empty()) || (tmp5 == abc))
                        {
                           
                               
                                break;
                            }

                    }   
                   
                
                
               
            
           
          
           
            
            std ::reverse(A.begin(), A.end());
           std :: reverse(B.begin(), B.end());
           /*cout <<endl<< A<< endl;
           cout << B << endl;*/
            answer.push_back(calculate(B, A, tmp3));
            tmp3 = "";
            A = "";
            B = "";
            reez = "";
            reez2 = "";
          
            
        }


       
           
    }
   std:: cout << endl << " your answer is : " << answer.back();


}










        //    /*  reverse(answer.begin(), answer.end());*/
        //    if (answer.back() == abc) {
        //        answer.pop_back();
        //    }
        //    

        //    
        //    for (int i = 0; i < answer.size(); i++) {
        //        reez += answer[i];
        //    }

        //    answer.clear();
     
        //    for (int i = reez.size(); i > 0; i--) {
        //        tmp4 += reez[i];
        //        if (isdigit(reez[i])) {
        //            A += tmp4;
        //            tmp4 = "";
        //            
        //           
        //        }
        //        else if (tmp4 == ".") {
        //            A += tmp4;
        //            tmp4 = ""; 
        //           
        //        }
        //        else if (tmp4 == abc) {
        //           
        //            for (int i = 0; i < reez.size() - A.size(); i++) {
        //                reez2 += reez[i];
        //            
        //            }
        //            if (reez2.back() == ' ') {
        //                reez2.pop_back();
        //            }
        //            for (int i = reez2.size(); i > 0; i--) {
        //                tmp5 += reez2[i];
        //               
        //                if (isdigit(reez2[i])) {
        //                    B += tmp5;
        //                    tmp5 = "";
        //                }
        //                else if (tmp5 == ".") {
        //                    B += tmp5;
        //                    tmp5 = "";
        //                    
        //                }
        //                else if (tmp5 == abc) {
        //                    
        //                            break;
        //                            tmp5 = "";
        //                    }
        //                  
        //                }
        //            }
        //            tmp4 = "";
        //        }

        //    }
        //    for (int i = 0; i < B.size(); i++) {
        //        if (B[i] == ' ')
        //        {
        //            B.erase(B.begin() + i);
        //            break;
        //        }
        //    }
        //for (int i = 0; i < reez2.size(); i++) {
        //    tmp6 += reez2[i];
        //    if (isdigit(reez2[i])) {
        //        answer.push_back(tmp6);
        //        tmp6 = "";
        //    }
        //    else if (tmp6 == ".") {
        //        answer.push_back(tmp6);
        //        tmp6 = "";
        //    }
        //    else if (tmp6 == abc) {
        //        break;
        //    }
        //}
        //    reez.clear();
        //    reez2.clear();
        //    answer.push_back(calculate(A, B, tmp3));         
        //    tmp3 = "";




















           
        //    for (int i = (reez.size()); i > 0; i--) {
        //        while (reez[i] != ' ') {
        //            reez.pop_back();

        //        }

        //    }
        //    if (reez.back() == ' ') {
        //        reez.pop_back();
        //    }

        //    for (int i = (reez.size()); i > 0; i--) {
        //        while ((!reez.empty()) || (reez[i] != ' ')) {
        //            B += reez[i];
        //        }
        //    }
        //    cout << endl << B;
        //    for (int i = (reez.size()); i > 0; i--) {
        //        while ((!reez.empty()) || (reez[i] != ' ')) {
        //            reez.pop_back();
        //        }
        //    }
        //    if (reez.back() == ' ') {
        //        reez.pop_back();
        //    }

        //    answer.push_back(calculate(A, B, tmp3));

        //    tmp3 = "";

        
   


        










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
    
    cout << endl <<" your answer is : " << answer.back();*/

    



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
