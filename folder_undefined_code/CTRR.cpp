#include "CTRR.h"



// 1.1
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '^') {
        return 3;
    }
    return -1;
}

string Infix2Postfix(string infix) {
    string postfix = "";
    stack<char> s;

    for (unsigned int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if (isalnum(c)) { // Nếu là toán hạng
            postfix += c;
        } else if (c == '(') { // Nếu là dấu mở ngoặc
            s.push(c);
        } else if (c == ')') { // Nếu là dấu đóng ngoặc
            while (!s.empty() && s.top() != '(') {        // pop các phần tử trong stack đến khi gặp '('  : lưu ý ko xuất ra (
                postfix += " ";
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Xóa dấu mở ngoặc
        } else { // Nếu là toán tử
            while (!s.empty() && precedence(c) <= precedence(s.top())) {
                postfix += " ";
                postfix += s.top();
                s.pop();
            }
            postfix += " ";
            s.push(c);
        }
    }

    while (!s.empty()) { // Xử lý các phần tử còn lại trong stack
        postfix += " ";
        postfix += s.top();
        s.pop();
    }

    return postfix;
}




// 1.2
int Kiem_Tra_Do_Uu_Tien(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '^') {
        return 3;
    }
    return -1;
}

string Infix2Prefix(string infix) {
    string prefix = "";
    stack<char> s;
    reverse(infix.begin(), infix.end());
    for (unsigned int i=0;i<infix.length();i++){
        if (isalnum(infix[i]) && isalnum(infix[i+1])){
            char str;
            str=infix[i];
            infix[i]=infix[i+1];
            infix[i+1]=str;
        } 
    }

    for (unsigned int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if (isalnum(c)) { // Nếu là toán hạng
            prefix += c;
        } else if (c == ')') { // Nếu là dấu đóng ngoặc
            s.push(c);
        } else if (c == '(') { // Nếu là dấu mở ngoặc
            while (!s.empty() && s.top() != ')') {  // Pop các phần tử trong stack đến khi gặp dấu đóng ngoặc
                prefix +=" ";
                prefix += s.top();
                s.pop();
            }
            s.pop(); // Xóa dấu đóng ngoặc
        } else { // Nếu là toán tử
            while (!s.empty() && Kiem_Tra_Do_Uu_Tien(c) < Kiem_Tra_Do_Uu_Tien(s.top())) {
                prefix +=" ";
                prefix += s.top();
                s.pop();
            }
            prefix +=" ";
            s.push(c);
        }
    }

    while (!s.empty()) { // Xử lý các phần tử còn lại trong stack
        prefix +=" ";
        prefix += s.top();
        s.pop();
    }
    reverse(prefix.begin(), prefix.end());
    for (unsigned int i=0;i<prefix.length();i++){
        if (isalnum(prefix[i]) && isalnum(prefix[i+1])){
            char str;
            str=prefix[i];
            prefix[i]=prefix[i+1];
            prefix[i+1]=str;
        } 
    }
    return prefix;
}

// 1.3
// Hàm kiểm tra xem một ký tự có phải là toán tử hay không
bool ToanTu(string &c) {
    return c =="+" || c =="-" || c =="*" || c == "/" || c == "^";
}

// Kiểm tra độ ưu tiên của các toán tử
int getPriority(char c) {
    if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

bool isOperator(string c) {
    return c == "+" || c == "-" || c == "*" || c == "/" || c == "^";
}

string evaluatePrefix(string prefix) {
    stack<double> operandStack;
    std::stringstream ss(prefix); // Tạo stringstream từ chuỗi prefix

    std::vector<std::string> elements;
    std::string element;
    while (ss >> element) {
        elements.push_back(element);
    }

    // Đảo ngược thứ tự các phần tử trong vector
    std::reverse(elements.begin(), elements.end());

    // In ra các phần tử theo thứ tự từ phải sang trái
    // for (const std::string& elem : elements) {
    //     std::cout << elem << std::endl;
    // }


    // Đọc biểu thức tiền tố từ phải qua trái
    for (const std::string& elem : elements) {
		//cout <<elem<<endl;
        // Nếu là toán hạng, đưa vào stack
        if (!isOperator(elem)) {
			//cout <<elem<<endl;
			double c_double=stod(elem);
			//cout <<c_double<<endl;
            operandStack.push(c_double);
			//cout <<operandStack.top()<<"aaaaaaaaa"<<endl;
        }
        // Nếu là toán tử, thực hiện phép toán với hai toán hạng đầu trong stack
        else if (isOperator(elem)) {
            double operand2 = operandStack.top();
            operandStack.pop();

            double operand1 = operandStack.top();
            operandStack.pop();
			if (elem =="+") operandStack.push(operand2 + operand1);
            else if (elem == "-") operandStack.push(operand2 - operand1);
            else if (elem == "*") operandStack.push(operand2 * operand1);
            else if (elem == "/") operandStack.push(operand2 / operand1);
            else if (elem == "^") operandStack.push(pow(operand2, operand1));
        }
    }
	//cout <<operandStack.top();

    double result = operandStack.top();

    // Làm tròn kết quả đến 4 chữ số sau dấu phẩy nếu kết quả là số thập phân
    if (std::floor(result) != result) {
        result = std::round(result * 10000.0) / 10000.0;
    }

    std::ostringstream oss;
    oss << std::fixed << std::setprecision(4) << result;
    std::string ketqua = oss.str();

    // Xóa các chữ số thập phân không cần thiết (sau dấu phẩy)
    size_t decimalPos = ketqua.find('.');
    if (decimalPos != string::npos) {
        size_t nonZeroPos = ketqua.find_last_not_of('0');
        if (nonZeroPos > decimalPos) {
            ketqua.erase(nonZeroPos + 1);
        } else {
            ketqua.erase(decimalPos);
        }
    }

    return ketqua;
}





//Hàm tính giá trị của biểu thức hậu tố
string evaluatePostfix(string postfix) {
    stack<double> operandStack;
    // chạy vòng lặp
    stringstream ss(postfix);
    string c;
    while (ss>>c){

        // Nếu là toán hạng, thêm vào stack
        if (ToanTu(c)==false) {
            double c_double=stod(c);
            operandStack.push(c_double);
            //cout <<operandStack.top();
        }
        // Nếu là toán tử, lấy hai toán hạng ra từ stack và tính toán kết quả
        else if (ToanTu(c)) {
            double operand1 = operandStack.top();  // lấy ra toán hạng đầu
            operandStack.pop(); // hủy nó đi
            double operand2 = operandStack.top();  // lấy ra toán hạng thứ 2
            operandStack.pop();  // hủy nó đi
            //cout <<operand1<<" "<<operand2;

            if (c =="+") operandStack.push(operand2 + operand1);
            else if (c == "-") operandStack.push(operand2 - operand1);
            else if (c == "*") operandStack.push(operand2 * operand1);
            else if (c == "/") operandStack.push(operand2 / operand1);
            else if (c == "^") operandStack.push(pow(operand2, operand1));
        }
    }

    //double ketqua = std::round(operandStack.top() * 10000.0) / 10000.0;
     double result = operandStack.top();

    // Làm tròn kết quả đến 4 chữ số sau dấu phẩy nếu kết quả là số thập phân
    if (floor(result) != result) {
        result = round(result * 10000.0) / 10000.0;
    }

    ostringstream oss;
    oss << fixed << std::setprecision(4) << result;
    string ketqua = oss.str();

    // Xóa các chữ số thập phân không cần thiết (sau dấu phẩy)
    size_t decimalPos = ketqua.find('.');
    if (decimalPos != string::npos) {
        size_t nonZeroPos = ketqua.find_last_not_of('0');
        if (nonZeroPos > decimalPos) {
            ketqua.erase(nonZeroPos + 1);
        } else {
            ketqua.erase(decimalPos);
        }
    }

    return ketqua;
}
string PostfixPrefixCalculator(string input){
    if (isalnum(input[0]))  return evaluatePostfix(input);   // hậu tố
    if (!isalnum(input[0])) return evaluatePrefix(input);   // tiền tố
    return " ";
}

// 2.1
int prec(char ch) {
    if (ch == '-')
        return 1;
    else if (ch == '~')
        return 3;
    else if (ch == '|' || ch == '&')
        return 2;
    else if (ch == '<')
        return 0;
    else
        return -1;
}

string LogicInfix2Postfix(std::string infix) {
    std::stack<char> st;
    std::string postfix;

    for (unsigned int i = 0; i < infix.size(); i++) {
        if (infix[i] == ' ') continue;
        else if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) postfix += infix[i];  // nếu là kí tự thì thêm vào
        else if (infix[i] == '(') st.push('(');  // nếu là ( push vào stack
        else if (infix[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                if (st.top() == '-') postfix += '>';
                if (st.top() == '<') postfix += "->";
                st.pop();
            }
            st.pop();
            } 
        else {  // nếu là toán tử 
            while (!st.empty() && prec(infix[i]) <= prec(st.top())) {
                postfix += st.top();
                if (st.top() == '-') postfix += '>';
                if (st.top() == '<') postfix += "->";
                st.pop();
            }
            st.push(infix[i]);
            if (st.top() == '-') i++;  // ->
            if (st.top() == '<') i = i + 2;  // <->
        }
    }
    while (!st.empty()) {
        postfix += st.top();
        if (st.top() == '-') postfix += '>';
        if (st.top() == '<') postfix += "->";
        st.pop();
    }

    return postfix;
}

// 2.2
int prec22(char ch) {
    if (ch == '-')
        return 1;
    else if (ch == '~')
        return 3;
    else if (ch == '|' || ch == '&')
        return 2;
    else if (ch == '<')
        return 0;
    else
        return -1;
}
std::string LogicInfix2Postfix22(std::string infix) {
    std::stack<char> st;
    std::string postfix;

    for (unsigned int i = 0; i < infix.size(); i++) {
        if (infix[i] == ' ') continue;
        else if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) postfix += infix[i];  // nếu là kí tự thì thêm vào
        else if (infix[i] == '(') st.push('(');  // nếu là ( push vào stack
        else if (infix[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                if (st.top() == '-') postfix += '>';
                if (st.top() == '<') postfix += "->";
                st.pop();
            }
            st.pop();
            } 
        else {  // nếu là toán tử 
            while (!st.empty() && prec22(infix[i]) < prec22(st.top())) {
                postfix += st.top();
                if (st.top() == '-') postfix += '>';
                if (st.top() == '<') postfix += "->";
                st.pop();
            }
            st.push(infix[i]);
            if (st.top() == '-') i++;  // ->
            if (st.top() == '<') i = i + 2;  // <->
        }
    }
    while (!st.empty()) {
        postfix += st.top();
        if (st.top() == '-') postfix += '>';
        if (st.top() == '<') postfix += "->";
        st.pop();
    }

    return postfix;
}

string LogicInfix2Prefix(string infix){
    string p1 ="";
    string p2 ="";

    for (unsigned int i=0;i<infix.size();i++) p1+=infix[infix.size()-1-i];
    for (unsigned int i=0;i<p1.size();i++){
    if (p1[i]=='(') p1[i]=')'; 
    else if (p1[i]==')') p1[i]='('; 
    else if (p1[i]=='>' && p1[i+1]=='-'&& p1[i+2]=='<') {
    p1[i]='<';
    p1[i+1]='-';
    p1[i+2]='>';
    } 
    else if (p1[i]=='>' && p1[i+1]=='-'){
    p1[i]='-';
    p1[i+1]='>';
}
}

    p1=LogicInfix2Postfix22(p1);

    for (unsigned int i=0;i<p1.size();i++){
    p2+=p1[p1.size()-1-i];
}
    for (unsigned int i=0;i<p2.size();i++){
    if (p2[i]=='>' && p2[i+1]=='-' && p2[i+2]=='<') {
    p2[i]='<';
    p2[i+1]='-';
    p2[i+2]='>';
} 
    else if (p2[i]=='>' && p2[i+1]=='-'){
    p2[i]='-';
    p2[i+1]='>';
}
}
    return p2;
}

// 2.3
char booltochar (bool a){

if (a==1) return '1';
else return '0';
}
bool chartobool (char a){
if (a=='1') return 1;
else return 0;
}
int isope(char x)
{
	if (x == '&' || x =='|' || x == '-' || x == '<' )
		return 1;
	else if ( x == '~') return 0;
	else return -1;
}
char tinh(char a, char x, char b)
{//cout<<a<<x<<b<<endl;
	bool ans;


	if(x == '&')
	{
		ans= chartobool(a) && chartobool(b);
	}

	else if (x == '|')
	{

		ans= chartobool(a)+chartobool(b);
	}
	else if (x == '-')
	{

		ans=(!chartobool(a))+chartobool(b);

	}
	else if (x == '<')
	{
		if (a==b) ans=1; else ans=0;
	}

	char _ans= booltochar(ans);
	return _ans;
}
string post(string input,string varlue){
for (unsigned int i=0;i<input.size()-1;i++){
    if (input[i]=='<'){
        input.erase(input.begin() + i+1);
        input.erase(input.begin() + i+1);
    }
    if (input[i]=='-'){
        input.erase(input.begin() + i+1);
    }
}
int count=1;
for (unsigned int i=0;i<varlue.size();i++){
    if (varlue[i]==' ') count++;
}
char vl[count];
stringstream ss(varlue);
for (int i=0;i<count;i++){
    ss>>vl[i];

}
for (unsigned int i=0;i<input.size();i++){
    for (int j=0;j<count/2;j++){
        if (input[i]==vl[j]){
            input[i]=vl[j+count/2];
            break;
        }

    }
}
//cout<<input<<endl;
Node * in = new Node [input.size()];
for (unsigned int i=0;i<input.size();i++){
    in[i].data=input[i];
}
Node* head= &in[0];
for (unsigned int i=0;i<input.size()-1;i++){
    in[i].pnext=&in[i+1];
}
in[input.size()-1].pnext=nullptr;

//TH chi 2 pt
while (head->pnext!=nullptr){
if (head->pnext->pnext==nullptr) {
    char a=head->data;
    char b=head->pnext->data;
    if (isope(a)==-1 && isope(b)==0 ){
    head->pnext->data=booltochar(!chartobool(a));
    head=head->pnext;
   // cout<<'0';
}} else {


    Node *temp=head;
    char a=temp->data;
    char b=temp->pnext->data;
    char c=temp->pnext->pnext->data;
//cout<<endl<<a<<b<<c<<endl;
    if (isope(a)==-1 && isope(b)==0 ){
        temp->pnext->data=booltochar(!chartobool(a));
        head=temp->pnext;
        //cout<<'1';
        continue;
        } else if(isope(b)==-1 && isope(c)==0 ){
        temp->pnext->pnext->data=booltochar(!chartobool(b));
        temp->pnext=temp->pnext->pnext;
       // cout<<'1';
        continue;

    } else if (isope(a)==-1 && isope(b)==-1 && isope(c)==1){

        head=temp->pnext->pnext;
        head->data=tinh(a,c,b);
        //cout<<'2';
        continue;
    } else {

    while (temp->pnext->pnext->pnext!=nullptr){
     a=temp->pnext->data;
     b=temp->pnext->pnext->data;
     c=temp->pnext->pnext->pnext->data;
     if (isope(a)==-1 && isope(b)==0 ){
        temp->pnext->pnext->data=booltochar(!chartobool(a));
        temp->pnext=temp->pnext->pnext;
        //cout<<'3';
        break;} else
    if (isope(b)==-1 && isope(c)==0 ){
        temp->pnext->pnext->pnext->data=booltochar(!chartobool(b));
        temp->pnext->pnext=temp->pnext->pnext->pnext;
        //cout<<'3';
        break;} else
    if  (isope(a)==-1 && isope(b)==-1 && isope(c)==1){
        temp->pnext->pnext->pnext->data=tinh(a,c,b);
        temp->pnext=temp->pnext->pnext->pnext;
        //cout<<'4';
        break;} else temp=temp->pnext;
}
}
}
}
delete[] in;
string ans;
if (head->pnext==nullptr) {
    if (head->data=='1') ans="TRUE"; else ans="FALSE";
}

return ans;
}
string pre(string input,string varlue){
//xoa <-> thanh <
for (unsigned int i=0;i<input.size()-1;i++){
    if (input[i]=='<'){
        input.erase(input.begin() + i+1);
        input.erase(input.begin() + i+1);
    }
    if (input[i]=='-'){
        input.erase(input.begin() + i+1);
    }
}
//xoa -> thanh -
int count=1;
for (unsigned int i=0;i<varlue.size();i++){
    if (varlue[i]==' ') count++;
}
char vl[count];
stringstream ss(varlue);
for (int i=0;i<count;i++){
    ss>>vl[i];

}
for (unsigned int i=0;i<input.size();i++){
    for (int j=0;j<count/2;j++){
        if (input[i]==vl[j]){
            input[i]=vl[j+count/2];
            break;
        }

    }
}
//cout<<input<<endl;
Node * in = new Node [input.size()];
for (unsigned int i=0;i<input.size();i++){
    in[i].data=input[i];
}
Node* head= &in[0];
for (unsigned int i=0;i<input.size()-1;i++){
    in[i].pnext=&in[i+1];
}
in[input.size()-1].pnext=nullptr;

//TH chi 2 pt
//Duyet
while (head->pnext!=nullptr){
if (head->pnext->pnext==nullptr) {
    char a=head->data;
    char b=head->pnext->data;
    if (isope(a)==0 && isope(b)==-1 ){
    head->pnext->data=booltochar(!chartobool(b));
    head=head->pnext;
   // cout<<'0';
}} else {


    Node *temp=head;
    char a=temp->data;
    char b=temp->pnext->data;
    char c=temp->pnext->pnext->data;
//cout<<endl<<a<<b<<c<<endl;
    if (isope(a)==0 && isope(b)==-1 ){
        temp->pnext->data=booltochar(!chartobool(b));
        head=temp->pnext;
      //  cout<<'1';
        continue;
    } else if(isope(b)==0 && isope(c)==-1 ){
        temp->pnext->pnext->data=booltochar(!chartobool(c));
        temp->pnext=temp->pnext->pnext;
       // cout<<'1';
        continue;

    } else if (isope(a)==1 && isope(b)==-1 && isope(c)==-1){

        head=temp->pnext->pnext;
        head->data=tinh(b,a,c);
        //cout<<'2';
        continue;
    } else {

    while (temp->pnext->pnext->pnext!=nullptr){
     a=temp->pnext->data;
     b=temp->pnext->pnext->data;
     c=temp->pnext->pnext->pnext->data;

    if (isope(a)==0 && isope(b)==-1 ){
        temp->pnext->pnext->data=booltochar(!chartobool(b));
        temp->pnext=temp->pnext->pnext;
       // cout<<'3';
        break;} else
    if (isope(b)==0 && isope(c)==-1 ){
        temp->pnext->pnext->pnext->data=booltochar(!chartobool(c));
        temp->pnext->pnext=temp->pnext->pnext->pnext;
        //cout<<'3';
        break;} else
    if  (isope(a)==1 && isope(b)==-1 && isope(c)==-1){
        temp->pnext->pnext->pnext->data=tinh(b,a,c);
        temp->pnext=temp->pnext->pnext->pnext;
       // cout<<'4';
        break;} else temp=temp->pnext;
}
}
}
}
delete[] in;
string ans;
if (head->pnext==nullptr) {
    if (head->data=='1') ans="TRUE"; else ans="FALSE";
}

return ans;
}
string LogicPostfixPrefixCalculator(string input,string varlue){
if (isope(input[0])==-1) return post(input,varlue); else return pre(input, varlue);
}



