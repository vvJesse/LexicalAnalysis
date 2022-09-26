
#include "DFA.h"

#include <utility>

using namespace std;

node::node(std::string str, std::vector<string> &vec,
        std::vector<int> &n_vec,std::vector<node> &set_of_node) {
    name = std::move(str);
    state_last_point = vec.size();
    for(int i = 0; i < state_last_point; i++){
        input[i] = vec[i];
        next[i] = n_vec[i];
    }
}


void DFA::set_all_nodes(){

    std::vector<string> vec;
    std::vector<int> n_vec;

    int t = 0;

    /*
     * void
     *
     * */
    vec.emplace_back("o"); n_vec.emplace_back(++t);
    node v_void("v", vec, n_vec,set_of_node); set_of_node.emplace_back(v_void);
    n_vec.clear(); vec.clear();

    vec.emplace_back("i"); n_vec.emplace_back(++t);
    node o_void("o", vec, n_vec,set_of_node); set_of_node.emplace_back(o_void);
    n_vec.clear(); vec.clear();

    vec.emplace_back("d"); n_vec.emplace_back(++t);
    node i_void("i", vec, n_vec, set_of_node); set_of_node.emplace_back(i_void);
    vec.clear(); n_vec.clear();

    node d_void("d", vec, n_vec, set_of_node); t++; set_of_node.emplace_back(d_void);
    vec.clear(); n_vec.clear();

    /*
     * int & if
     *
     * */
//    cout << t << endl;
    vec.emplace_back("f"); vec.emplace_back("n"); n_vec.emplace_back(++t); n_vec.emplace_back(t+1);
    node i_int("i", vec, n_vec,set_of_node); set_of_node.emplace_back(i_int);
    n_vec.clear(); vec.clear();

    // if
    node f_if("f", vec, n_vec, set_of_node); t++; set_of_node.emplace_back(f_if);
    vec.clear(); n_vec.clear();

    vec.emplace_back("t"); n_vec.emplace_back(++t);
    node n_int("n", vec, n_vec,set_of_node); set_of_node.emplace_back(n_int);
    n_vec.clear(); vec.clear();

//    cout << t << endl;
    node t_int("t", vec, n_vec, set_of_node); t++; set_of_node.emplace_back(t_int);
    vec.clear(); n_vec.clear();

    /*
     * float
     *
     * */
    vec.emplace_back("o"); vec.emplace_back("l"); n_vec.emplace_back(++t); n_vec.emplace_back(t+2);
    node f_float("f", vec, n_vec,set_of_node); set_of_node.emplace_back(f_float);
    n_vec.clear(); vec.clear();

    vec.emplace_back("r"); n_vec.emplace_back(++t);
    node o_for("o", vec, n_vec,set_of_node); set_of_node.emplace_back(o_for);
    n_vec.clear(); vec.clear();

    node r_for("r", vec, n_vec, set_of_node); t++; set_of_node.emplace_back(r_for);
    vec.clear(); n_vec.clear();

    vec.emplace_back("o"); n_vec.emplace_back(++t);
    node l_float("l", vec, n_vec,set_of_node); set_of_node.emplace_back(l_float);
    n_vec.clear(); vec.clear();

    vec.emplace_back("a"); n_vec.emplace_back(++t);
    node o_float("o", vec, n_vec,set_of_node); set_of_node.emplace_back(o_float);
    n_vec.clear(); vec.clear();

    vec.emplace_back("t"); n_vec.emplace_back(++t);
    node a_float("a", vec, n_vec,set_of_node); set_of_node.emplace_back(a_float);
    n_vec.clear(); vec.clear();

    node t_float("t", vec, n_vec, set_of_node); t++; set_of_node.emplace_back(t_float);
    vec.clear(); n_vec.clear();



    // double
    vec.emplace_back("o"); n_vec.emplace_back(++t);
    node d_double_or_do("d", vec, n_vec,set_of_node); set_of_node.emplace_back(d_double_or_do);
    n_vec.clear(); vec.clear();

    vec.emplace_back("u"); n_vec.emplace_back(++t);
    node o_double_or_do("o", vec, n_vec,set_of_node); set_of_node.emplace_back(o_double_or_do);
    n_vec.clear(); vec.clear();

    vec.emplace_back("b"); n_vec.emplace_back(++t);
    node u_double("u", vec, n_vec,set_of_node); set_of_node.emplace_back(u_double);
    n_vec.clear(); vec.clear();

    vec.emplace_back("l"); n_vec.emplace_back(++t);
    node b_double("b", vec, n_vec,set_of_node); set_of_node.emplace_back(b_double);
    n_vec.clear(); vec.clear();

    vec.emplace_back("e"); n_vec.emplace_back(++t);
    node l_double("l", vec, n_vec,set_of_node); set_of_node.emplace_back(l_double);
    n_vec.clear(); vec.clear();

    node e_float("e", vec, n_vec, set_of_node); t++; set_of_node.emplace_back(e_float);
    vec.clear(); n_vec.clear();



    // else
    vec.emplace_back("l"); n_vec.emplace_back(++t);
    node e_else_first("e", vec, n_vec,set_of_node); set_of_node.emplace_back(e_else_first);
    n_vec.clear(); vec.clear();

    vec.emplace_back("s"); n_vec.emplace_back(++t);
    node l_else("l", vec, n_vec,set_of_node); set_of_node.emplace_back(l_else);
    n_vec.clear(); vec.clear();

    vec.emplace_back("e"); n_vec.emplace_back(++t);
    node s_else("s", vec, n_vec,set_of_node); set_of_node.emplace_back(s_else);
    n_vec.clear(); vec.clear();

    node e_else_last("e", vec, n_vec, set_of_node); t++; set_of_node.emplace_back(e_else_last);
    vec.clear(); n_vec.clear();


    // while
    vec.emplace_back("h"); n_vec.emplace_back(++t);
    node w_while("w", vec, n_vec,set_of_node); set_of_node.emplace_back(w_while);
    n_vec.clear(); vec.clear();

    vec.emplace_back("i"); n_vec.emplace_back(++t);
    node h_while("h", vec, n_vec,set_of_node); set_of_node.emplace_back(h_while);
    n_vec.clear(); vec.clear();

    vec.emplace_back("l"); n_vec.emplace_back(++t);
    node i_while("i", vec, n_vec,set_of_node); set_of_node.emplace_back(i_while);
    n_vec.clear(); vec.clear();

    vec.emplace_back("e"); n_vec.emplace_back(++t);
    node l_while("l", vec, n_vec,set_of_node); set_of_node.emplace_back(l_while);
    n_vec.clear(); vec.clear();

    node e_while("e", vec, n_vec, set_of_node); t++; set_of_node.emplace_back(e_while);
    vec.clear(); n_vec.clear();


    /*
     *  标识符
     */
    vec.emplace_back("letter"); vec.emplace_back("digit"); n_vec.emplace_back(t++); n_vec.emplace_back(t);
    node id_letter("letter", vec, n_vec, set_of_node);
    set_of_node.emplace_back(id_letter);
    vec.clear(); n_vec.clear();

    vec.emplace_back("letter"); vec.emplace_back("digit"); n_vec.emplace_back(t-1); n_vec.emplace_back(t++);
    node id_digit("digit", vec, n_vec, set_of_node);
    set_of_node.emplace_back(id_digit);
    vec.clear(); n_vec.clear();

    /*
     * 无符号整数
     */

    vec.emplace_back("digit"); n_vec.emplace_back(t);
    node integer_digit("digit", vec, n_vec, set_of_node);
    set_of_node.emplace_back(integer_digit);
    vec.clear(); n_vec.clear();

    /*
     * 保留字全都连到标识符节点上
     */

    for(int i = 0; i <= 29; i++){
        int state_point = (set_of_node.at(i).state_last_point)++;
        set_of_node.at(i).input[state_point] = "letter";
        set_of_node.at(i).next[state_point] = 30;
    }

    /*
     * 符号连接 + - * ; , ( ) { }
     * > = < ! /
     */

    t++;
    vec.emplace_back("+"); vec.emplace_back("="); n_vec.emplace_back(++t); n_vec.emplace_back(t+1);
    node add_or_auto_add1("+", vec, n_vec,set_of_node); set_of_node.emplace_back(add_or_auto_add1);
    n_vec.clear(); vec.clear();

    t++;
    node auto_add2("+", vec, n_vec,set_of_node);
    set_of_node.emplace_back(auto_add2);

    t++;
    node add_eq_e("=", vec, n_vec,set_of_node);
    set_of_node.emplace_back(add_eq_e);

    vec.emplace_back("-"); vec.emplace_back("="); n_vec.emplace_back(++t); n_vec.emplace_back(t+1);
    node sub_or_auto_sub1("-", vec, n_vec,set_of_node); set_of_node.emplace_back(sub_or_auto_sub1);
    n_vec.clear(); vec.clear();

    t++;
    node auto_sub2("-", vec, n_vec,set_of_node);
    set_of_node.emplace_back(auto_sub2);

    t++;
    node sub_eq_e("=", vec, n_vec,set_of_node);
    set_of_node.emplace_back(sub_eq_e);

    vec.emplace_back("="); n_vec.emplace_back(++t);
    node mul_or_mul_eq("*", vec, n_vec,set_of_node); set_of_node.emplace_back(mul_or_mul_eq);
    n_vec.clear(); vec.clear();

    t++;
    node mul_eq_e("=", vec, n_vec,set_of_node);
    set_of_node.emplace_back(sub_eq_e);

    node semicolon(";", vec, n_vec, set_of_node);
    set_of_node.emplace_back(semicolon);

    node comma(",", vec, n_vec, set_of_node);
    set_of_node.emplace_back(comma);

    node brackets_left("(", vec, n_vec, set_of_node);
    set_of_node.emplace_back(brackets_left);

    node brackets_right(")", vec, n_vec, set_of_node);
    set_of_node.emplace_back(brackets_right);

    node attribute_left("{", vec, n_vec, set_of_node);
    set_of_node.emplace_back(attribute_left);

    node attribute_right("}", vec, n_vec, set_of_node);
    set_of_node.emplace_back(attribute_right);


    /*
     * 符号，但双目
     */

    t = set_of_node.size();

    // 大于等于
    vec.emplace_back("="); n_vec.emplace_back(++t);
    vec.emplace_back(">"); n_vec.emplace_back(t+1);
    node be_b(">", vec, n_vec,set_of_node); set_of_node.emplace_back(be_b);
    n_vec.clear(); vec.clear();

    t++;
    node be_e("=", vec, n_vec,set_of_node);
    set_of_node.emplace_back(be_e);

    t++;
    node right_m(">", vec, n_vec,set_of_node);
    set_of_node.emplace_back(right_m);


    // 小于等于
    vec.emplace_back("="); vec.emplace_back("<"); vec.emplace_back(">");
    n_vec.emplace_back(++t); n_vec.emplace_back(t+1); n_vec.emplace_back(t+2);
    node le_l("<", vec, n_vec,set_of_node); set_of_node.emplace_back(le_l);
    n_vec.clear(); vec.clear();

    t++;
    node le_e("=", vec, n_vec,set_of_node);
    set_of_node.emplace_back(le_e);

    t++;
    node left_m("<", vec, n_vec,set_of_node);
    set_of_node.emplace_back(left_m);

    t++;
    node ne_b(">", vec, n_vec,set_of_node);
    set_of_node.emplace_back(ne_b);


    // 不等于

    vec.emplace_back("="); n_vec.emplace_back(++t);
    node neg_n("!", vec, n_vec,set_of_node); set_of_node.emplace_back(neg_n);
    n_vec.clear(); vec.clear();

    t++;
    node neg_e("=", vec, n_vec,set_of_node);
    set_of_node.emplace_back(neg_e);


    // 注释

    vec.emplace_back("*"); n_vec.emplace_back(++t); vec.emplace_back("="); n_vec.emplace_back(t+1);
    node div_e_or_annotate_a("/", vec, n_vec,set_of_node); set_of_node.emplace_back(div_e_or_annotate_a);
    n_vec.clear(); vec.clear();

    t++;
    node annotate_b("*", vec, n_vec,set_of_node);
    set_of_node.emplace_back(annotate_b);

    t++;
    node div_e("=", vec, n_vec,set_of_node);
    set_of_node.emplace_back(div_e);

    vec.emplace_back("="); n_vec.emplace_back(++t);
    node equal_or_not("=", vec, n_vec,set_of_node); set_of_node.emplace_back(equal_or_not);
    n_vec.clear(); vec.clear();

    t++;
    node eq("=", vec, n_vec,set_of_node);
    set_of_node.emplace_back(eq);

    vec.emplace_back("&"); n_vec.emplace_back(++t);
    node and_logic("&", vec, n_vec,set_of_node); set_of_node.emplace_back(and_logic);
    n_vec.clear(); vec.clear();

    t++;
    node and_logic2("&", vec, n_vec,set_of_node);
    set_of_node.emplace_back(and_logic2);

    vec.emplace_back("|"); n_vec.emplace_back(++t);
    node or_logic("|", vec, n_vec,set_of_node); set_of_node.emplace_back(or_logic);
    n_vec.clear(); vec.clear();

    t++;
    node or_logic2("|", vec, n_vec,set_of_node);
    set_of_node.emplace_back(or_logic2);

    t++;
    node quotaion_double("\"", vec, n_vec,set_of_node);
    set_of_node.emplace_back(quotaion_double);

    t++;
    node quotation_single("'", vec, n_vec,set_of_node);
    set_of_node.emplace_back(quotation_single);

    t++;
    node left_brack("[", vec, n_vec,set_of_node);
    set_of_node.emplace_back(left_brack);

    t++;
    node right_brack("]", vec, n_vec,set_of_node);
    set_of_node.emplace_back(right_brack);

    /*
     *  这部分用来测试！！！！！！！
     */

    int count = 0;
    for(auto iter = set_of_node.begin(); iter != set_of_node.end(); iter++, count++){
        cout << count << " " << iter->name << ":    ";
        if(iter->name == "letter"){
            cout << "";
        }
        for(int j = 0; j < iter->state_last_point; j++){
            cout << iter->next[j] << "." << iter->input[j] << "    ";
        }
        cout << endl;
    }


}


set<char> symbols = {'+','-','*',';',',','(',')','{','}','<','>','=','!','/','&','|','"','\'','[',']'};


bool is_valid_symbol(char& str){
    return symbols.find(str) != symbols.end();
}


bool match_word(const string& require, string provide){
    if(require == "letter")
        return isalpha(provide[0]) && provide.length()==1;
    else if(require == "digit")
        return isdigit(provide[0]);
    else
        return require == provide;
}


int DFA::find_end(const string& buf, int cur_state, int matched_length){

    if(matched_length == buf.length())
    {
        return matched_length;
    }

    int unknown_bug2 = cur_state;
    for(int i = 0; i < set_of_node[unknown_bug2].state_last_point; i++)
    {

        if(match_word(set_of_node[unknown_bug2].input[i],buf.substr(matched_length, 1)))
        {
            setbuf(stdout, nullptr);
            int unknown_bug1 =  set_of_node.at(cur_state).next[i];
            return find_end(buf, unknown_bug1, matched_length+1);
        }

    }

    return matched_length;
}


void DFA::out_type(string &buf, int type, ofstream& out){
    if(!type){
//        cout << "(\"" << buf << "\", " << out_type_map[buf] << ")" << endl;
        out << "(\"" << buf << "\", " << out_type_map[buf] << ")" << endl;
    }else{
//        cout << "(\"" << buf << "\", " << type << ")" << endl;
        out << "(\"" << buf << "\", " << type << ")" << endl;
    }
}


int DFA::judge_a_word(string buf, ofstream &out){

    //matched_length: 已配对的长度
    int m_len = 0;

    //首位为字母
    //是标识符或保留字
    if(isalpha(buf[0]))
    {

        //默认标识符为开始节点
        int cur = IDENTIFIER_INDEX;
        bool restricted_word_flag = false;

        //判断是否可能是保留字
        if(buf[0]=='v'||buf[0]=='i'||buf[0]=='f'||buf[0]=='d'||buf[0]=='e'||buf[0]=='w')
        {
            cur = map_of_char[buf[0]];
            restricted_word_flag = true;
        }

        // 遍历子树，求可配对的最大长度
        m_len = find_end(buf, cur, 1);

        if(m_len > MAX_IDENTIFIER_LENGTH)
        {
//            cout << "Identifier should be no more than 32 characters." << endl;
            out << "Identifier should be no more than 32 characters." << endl;
        } else{

            // 未配对部分处理
            if (m_len != buf.length())
            {
                // 理论上，未配对部分不可能以字母或数字开头
                // 因此这里只需看是否是正确符号
                if (is_valid_symbol(buf[m_len]))
                {
                    if (restricted_word_flag)
                    {
                        string tmp = buf.substr(0, m_len);
                        out_type(tmp, 0, out);
                    }
                    else{
                        string tmp = buf.substr(0, m_len);
                        out_type(tmp, IDENTIFIER_OUT_TYPE, out);
                    }
                    judge_a_word(buf.substr(m_len, buf.length() - m_len), out);
                } else {
//                    cout << buf << " can not be resolved." << endl;
                    out << buf << " can not be resolved." << endl;
                }
            } else {
                out_type(buf, IDENTIFIER_OUT_TYPE, out);
            }

        }
    }else if(isdigit(buf[0]))
    {

        m_len = find_end(buf, INTEGER_INDEX, 1);

        if(m_len!=buf.size())
        {
            if(is_valid_symbol(buf[m_len]))
            {
                string tmp = buf.substr(0, m_len);
                out_type(tmp, INTEGER_OUT_TYPE, out);
                judge_a_word(buf.substr(m_len, buf.length()-m_len), out);

            } else{
//                cout << buf << "can not be resolved." << endl;
                out << buf << "can not be resolved." << endl;
            }
        } else{
            out_type(buf, INTEGER_OUT_TYPE, out);
        }

    }else if(is_valid_symbol(buf[0]))
    {
        m_len = find_end(buf, map_of_char[buf[0]], 1);

        if(m_len != buf.length())
        {
            string tmp = buf.substr(0, m_len);
            out_type(tmp, 0, out);
            judge_a_word(buf.substr(m_len, buf.size()-m_len), out);

        }else{
            out_type(buf, 0, out);
        }

    } else{
//        cout << "Invalid character detected: " << buf[0] << " from " << buf << endl;
        out << "Invalid character detected: " << buf[0] << " from " << buf << endl;
    }

}


void DFA::run_DFA(std::string& filename) {
    ifstream fin;
    fin.open(filename, ios::in);
    if(!fin.is_open())
    {
        cout << "file_open_error." << endl;
        return;
    }

    string buf;
    ofstream fout;
    fout.open(filename.substr(0, filename.length()-4)+"_m.txt", ios::out);

    while(fin >> buf)
    {
        judge_a_word(buf, fout);
    }

    fin.close();
//    judge_a_word("void>=1>1");

}


void DFA::set_map() {

    map_of_char['v'] = 0;
    map_of_char['i'] = 4;
    map_of_char['f'] = 8;
    map_of_char['d'] = 15;
    map_of_char['e'] = 21;
    map_of_char['w'] = 25;

    map_of_char['+'] = 33;
    map_of_char['-'] = 36;
    map_of_char['*'] = 39;
    map_of_char[';'] = 41;
    map_of_char[','] = 42;
    map_of_char['('] = 43;
    map_of_char[')'] = 44;
    map_of_char['{'] = 45;
    map_of_char['}'] = 46;
    map_of_char['>'] = 47;
    map_of_char['<'] = 50;
    map_of_char['!'] = 54;
    map_of_char['/'] = 56;
    map_of_char['='] = 59;
    map_of_char['&'] = 61;
    map_of_char['|'] = 63;
    map_of_char['"'] = 65;
    map_of_char['\''] = 66;
    map_of_char['['] = 67;
    map_of_char[']'] = 68;

    int a = 1;
    out_type_map["void"] = a++;
    out_type_map["if"] = a++;
    out_type_map["int"] = a++;
    out_type_map["for"] = a++;
    out_type_map["float"] = a++;
    out_type_map["double"] = a++;
    out_type_map["else"] = a++;
    out_type_map["while"] = a++;
    out_type_map["+"] = a++;
    out_type_map["++"] = a++;
    out_type_map["+="] = a++;
    out_type_map["-"] = a++;
    out_type_map["--"] = a++;
    out_type_map["-="] = a++;
    out_type_map["*"] = a++;
    out_type_map["*="] = a++;
    out_type_map["="] = a++;
    out_type_map[";"] = a++;
    out_type_map[","] = a++;
    out_type_map["("] = a++;
    out_type_map[")"] = a++;
    out_type_map["{"] = a++;
    out_type_map["}"] = a++;
    out_type_map[">"] = a++;
    out_type_map[">="] = a++;
    out_type_map[">>"] = a++;
    out_type_map["<"] = a++;
    out_type_map["<="] = a++;
    out_type_map["<<"] = a++;
    out_type_map["<>"] = a++;
    out_type_map["!"] = a++;
    out_type_map["!="] = a++;
    out_type_map["/"] = a++;
    out_type_map["/*"] = a++;
    out_type_map["/="] = a++;
    out_type_map["="] = a++;
    out_type_map["=="] = a++;
    out_type_map["&"] = a++;
    out_type_map["&&"] = a++;
    out_type_map["|"] = a++;
    out_type_map["||"] = a++;
    out_type_map["\""] = a++;
    out_type_map["'"] = a++;
    out_type_map["["] = a++;
    out_type_map["]"] = a;

}


int Check(string readline)
{
    //非空串判断
    for(int n=0;n<readline.length();n++)
    {
        //如果有元素不是空格或者回车，该串非空
        if(readline[n]!=9&&readline[n]!=32&&readline[n]!=13)
        {
            //cout<<readline+"非空"<<endl;
            return 1;
        }
    }
    return 0;
}


int LineProcess(string readline,int &readpos,int &startpos,int &endpos,int& status, string &outname)
{
    //写入文件
    fstream out;
    out.open(outname, fstream::out | ios_base::app);

    //status 1正常读取 2同行待匹配 3异行待匹配
    int j=readline.length();
    int flag=0;//没有注释
    //cout<<"当前状态："<<status<<" 当前行："<<readline<<endl;
    //cout<<"当前行："<<readline<<"当前读取位置："<<readpos<<readline[readpos]<<endl;
    //cout<<" 当前行："<<readline<<endl;

    //跳过空行
    if(0==j)
    {
        //cout<<"空行"<<endl;
        return 0;
    }

    //逐字符读取
    for(int n=readpos;n<j;n++)
    {
        //cout<<"当前状态："<<status<<"当前读取位置："<<n<<endl;
        //cout<<"进入循环"<<endl;
        //cout<<"当前行："<<readline<<"当前读取位置："<<readline[n]<<endl;
        //读取到//
        if(readline[n]=='/'&&readline[n+1]=='/')
        {
            //cout<<"当前行："<<readline<<"当前读取位置："<<readline[n]<<endl;
            startpos=n;
            //输出/之前的内容
            //cout<<"//输出："<<endl;
            //cout<<"//前注释长度："<<readline.substr(0,n).length()<<endl;
            //输出非空字符串
            if(Check(readline.substr(0,n)))
            {
                out<<readline.substr(0,n)<<endl;
                cout<<readline.substr(0,n)<<endl;
            }
            //读取下一行
            readpos=0;
            return 0;
        }
        //读取到/*
        if(readline[n]=='/'&&readline[n+1]=='*')
        {
            //cout<<"当前行："<<readline<<"当前读取位置："<<readline[n]<<endl;
            //标记
            //startpos=n;
            //输出/之前的内容,不换行,一次只输出一部分
            //cout<<"/*输出："<<endl;
            out<<readline.substr(startpos,n-startpos);//0，n
            cout<<readline.substr(startpos,n-startpos);//n-startpos
            //暂不换行
            //状态变更为同行待匹配
            status=2;
            //标记读取位置为*的下一位
            readpos=n+2;
            //继续读本行
            return 1;

            //old
            //cout<<"发现注释/*："<<readline<<endl;
            //cout<<startpos<<readline[startpos]<<endpos<<readline[endpos]<<endl;
            //system("pause");
            //break;
        }
        //读取到*/
        if(readline[n]=='*'&&readline[n+1]=='/')
        {
            //cout<<"readpos:"<<readpos<<endl;

            //恢复正常状态
            status=1;

            //标记readpos为/的后一位
            if(n<j-2)
            {
                //如果还有，从此开始输出
                startpos=n+2;
                readpos=n+2;
                //cout<<"readpos:"<<readpos<<endl;
                //继续读本行
                return 1;
            }
            else
            {
                //读取下一行
                return 0;
            }

            //if(n!=j-2)return 1;
            //else if(j-2==n)return 0;//读取下一行

            //old
            //flag=3;
            //endpos=n+1;
            //cout<<"发现注释*/："<<readline<<endl;
            //cout<<startpos<<readline[startpos]<<endpos<<readline[endpos]<<endl;
            //system("pause");
            //想继续读第二个注释，就不能break
            //break;
        }
        //读取到本行末尾
        if(n==j-1)//▲出错点 n==j进入死循环
        {
            //cout<<"读取到本行末尾"<<endl;
            //cout<<"当前状态："<<status<<endl;

            //如果同行待匹配没匹配到，就变成异行待匹配
            if(2==status)
            {
                //cout<<"同行待匹配没匹配到，变成异行待匹配 "<<endl;
                status=3;
                //读取下一行
                readpos=0;
                return 0;
            }
            else if(3==status) //▲出错点 status=3 修改了变量的值
            {
                //cout<<""<<endl;
                //cout<<"是异行待匹配状态，现在读取下一行"<<endl;
                //读取下一行
                readpos=0;
                return 0;
            }
            else if(1==status)
            {
                //正常状态
                //输出本行未输出过的字符，换行
                //cout<<"是正常状态，输出本行，换行，再读取下一行"<<endl;
                out<<readline.substr(startpos)<<endl;
                cout<<readline.substr(startpos)<<endl;
                //读取下一行
                readpos=0;
                return 0;
            }
        }
    }
    //system("pause");
}


string DFA::clear_annotation(string &name)
{
    //读入 ：过滤单行的注释，将注释内容全部截取
    fstream in;
    in.open(name,ios::in);

    //写入文件
    string outname = name.substr(0, name.length()-4) + "_m.txt";
    fstream out;
    out.open(outname, fstream::out | ios_base::trunc);

    int n=0;//当前读取位置
    int endpos=0; //用后记得初始化
    int startpos=0;
    int status=1;
    int readpos=0;
    string readline;
    while (getline(in, readline))
    {
        //cout<<"读取下一行"<<endl;
        int res=0;
        startpos=0;
        //读取下一行0，继续读本行1
        while(res=LineProcess(readline,readpos,startpos,endpos,status, outname))
        {
            //cout<<"继续读本行"<<endl;
            res=0;
            //system("pause");
        }
    }
    in.close();
    out.close();
    return outname;

}
