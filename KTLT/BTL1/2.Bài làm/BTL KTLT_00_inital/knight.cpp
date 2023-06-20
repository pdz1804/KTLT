#include "knight.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}

float BaseDamage12345(int MaSK) {
    if (MaSK == 1) return 1.0;
    if (MaSK == 2) return 1.5;
    if (MaSK == 3) return 4.5;
    if (MaSK == 4) return 7.5;
    if (MaSK == 5) return 9.5;
    else return 0;
}

int Level(int ThuTuSuKien) {
    int b = ThuTuSuKien % 10;
    int levelO = (ThuTuSuKien > 6) ? ((b > 5) ? b : 5) : b;
    return levelO;
}

int convert_string_int(string s)
{
    // The idea is to use the ASCII value of the digits from 0 to 9 start from 48 � 57
    // Initialize a variable 
    int num = 0;
    int n = s.length();

    // Iterate till length of the string 
    for (int i = 0; i < n; i++) {
        // Subtract 48 from the current digit 
        num = num * 10 + (int(s[i]) - 48);
    }
    // Print the answer 
    return num;
}

// PASS AN ARRAY BY REFERENCE
void cacsukien(string a, int(&ARR)[1024], int(&size)) {
    //cout << "string a = \"" << a << "\"" << endl;
    int arr[1024], n;
    int t = 0;
    int index1 = -1, index2;
    //cout << "length a " << a.length() << endl;
    for (int i = 0; i < a.length(); i++) {
        //cout << "i " << i << endl;
        //cout << "a[i] " << a[i] << endl;
        // XU LI CHUOI
        // TIM CAC VI TRI INDEX LA KHOANG TRANG -> TAO SUBSTR TU STR GIUA 2 KHOANG TRANG -> CONVERT TO INT -> GHI VAO ARRAY
        if (a[i] == ' ') {
            index2 = i;
            n = convert_string_int(a.substr(index1 + 1, index2 - index1 - 1));
            //cout << "n " << n << endl;
            arr[t] = n;
            index1 = index2;
            t++;
        }
        else if (i == (a.length() - 2)) {
            n = convert_string_int(a.substr(index1 + 1, i - index1));
            //cout << "n " << n << endl;
            arr[t] = n;
            t++;
        }
        else {
            continue;
        }
    }

    // ASSIGN THE VALUE FROM THIS FUNC TO AN ARRAY IN adventureToKoopaTest
    for (int j = 0; j < t; j++) {
        ARR[j] = arr[j];
    }
    size = t;
}

// GET FILE NAME TO AN ARRAY OF FILE
void Used_File(string a, string(&File)[1024], int(&size)) {
    //cout << "string a = \"" << a << "\"" << endl;
    string arr[1024], n;
    int t = 0;
    int index1 = -1, index2;
    //cout << "length a " << a.length() << endl;
    for (int i = 0; i < a.length(); i++) {
        //cout << "i " << i << endl;
        //cout << "a[i] " << a[i] << endl;
        // XU LI CHUOI
        // TIM CAC VI TRI INDEX LA KHOANG TRANG -> TAO SUBSTR TU STR GIUA 2 KHOANG TRANG -> CONVERT TO INT -> GHI VAO ARRAY
        if (a[i] == ',') {
            index2 = i;
            n = a.substr(index1 + 1, index2 - index1 - 1);
            //cout << "n " << n << endl;
            arr[t] = n;
            index1 = index2;
            t++;
        }
        else if (i == (a.length() - 1)) {
            n = a.substr(index1 + 1, i - index1);
            //cout << "n " << n << endl;
            arr[t] = n;
            t++;
        }
        else {
            continue;
        }
    }

    // ASSIGN THE VALUE FROM THIS FUNC TO AN ARRAY IN adventureToKoopaTest
    for (int j = 0; j < t; j++) {
        File[j] = arr[j];
    }
    size = t;
}

// CUT NUMBER TO GET THE MUSHROOM ID
void cutnumber(int n, int (&idNam)[1024], int (&NumNam)) {
    string s;
    int j = 0;
    s = to_string(n);
    for (int i = 2; i < s.length(); i++) {
        idNam[j] = s[i] - 48;
        j++;
    }
    NumNam = j;    
}

// CHECK PRIME NUMBER
bool songuyento(int n) {
    int uoc = 0;
    bool check;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            uoc += 1;
        }
        if (uoc > 2) {
            check = false;
        }
        if ((uoc == 2) && (i == n)) {
            check = true;
        }
    }
    return check;
}

// GET THE SEQUENCE - MUSHROOM
void Get_Seq(string a, int (&SEQ)[1024], int(&size)) {
    //cout << "string a = \"" << a << "\"" << endl;
    string arr[1024], n;
    int t = 0;
    int index1 = -1, index2;
    //cout << "length a " << a.length() << endl;
    for (int i = 0; i < a.length(); i++) {
        //cout << "i " << i << endl;
        //cout << "a[i] " << a[i] << endl;
        // XU LI CHUOI
        // TIM CAC VI TRI INDEX LA KHOANG TRANG -> TAO SUBSTR TU STR GIUA 2 KHOANG TRANG -> CONVERT TO INT -> GHI VAO ARRAY
        if (a[i] == ',') {
            index2 = i;
            n = a.substr(index1 + 1, index2 - index1 - 1);
            //cout << "n " << n << endl;
            arr[t] = n;
            index1 = index2;
            t++;
        }
        else if (i == (a.length() - 1)) {
            n = a.substr(index1 + 1, i - index1);
            //cout << "n " << n << endl;
            arr[t] = n;
            t++;
        }
        else {
            continue;
        }
    }

    // ASSIGN THE VALUE FROM THIS FUNC TO AN ARRAY IN THE MUSHROOM DESCRIP
    for (int j = 0; j < t; j++) {
        if (arr[j][0] == '-') {
            SEQ[j] = -convert_string_int(arr[j].substr(1, arr[j].length() - 1));
        }
        else {
            SEQ[j] = convert_string_int(arr[j]);
        }
    }
    size = t;
}

// CHECK IF A SEQUENCE HAS THE SHAPE OF A MOUNTAIN
bool CheckMountain(int (&arr)[1024], int socacso, int (&mtx), int (&mti)) {
    // Xu li dinh - Tim gia tri lon nhat va vi tri (index) cua dinh
    mtx = arr[0];
    mti = 0;
    for (int i = 0; i < socacso; i++) {
        if (arr[i] > mtx) {
            mti = i;
            mtx = arr[i];
        }
    }
    
    // check if nui?
    bool check = true;
    // Dinh nui tai index 0
    if (mti == 0) {
        for (int i = 0; (i <= socacso - 2) && check; i++) {
            if (arr[i] <= arr[i+1]) {
                check = false;
            }
        }
    }
    // Dinh nui tai index cuoi cung (index = socacso - 1)
    else if (mti == socacso - 1) {
        for (int i = socacso - 1; (i > 0) && check; i--) {
            if (arr[i] <= arr[i-1]) {
                check = false;
            }
        }
    }
    // Dinh nui nam trong khoang giua 0 va socacso - 1
    else {
        // Tu cac so ben trai den dinh nui
        for (int i = 0; (i <= mti) && check; i++) {
            if (arr[i] >= arr[i+1]) {
                check = false;
            }
        }
        // Tu dinh nui den ben phai
        for (int i = mti; (i >= socacso - 1) && check; i++) {
            if (arr[i] <= arr[i+1]) {
                check = false;
            }
        }
    }
    return check;
}


void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue) {
    string s;
    string file_used;
    ifstream ifs;
    ifs.open(file_input);
    ifs >> HP >> level >> remedy >> maidenkiss >> phoenixdown;
    getline(ifs, s);
    getline(ifs, s);
    getline(ifs, file_used);
    ifs.close();
    rescue = - 1;
    // DANH SACH CAC SU KIEN DIEN RA
    int CacSuKien[1024];
    int Num_Event;
    cacsukien(s, CacSuKien, Num_Event);

    // DANH SACH CAC FILE SU DUNG
    string File[1024];
    int Num_File;
    Used_File(file_used, File, Num_File);

    // XU LI PHAN MO TA
    int maxHP = HP;
    int level_before_ech;
    int tihon = -1;
    int ech = -1;
    int meet_asclepius = 0;
    int meet_merlin = 0;

    // MO TA 10 - VUA ARTHUR - CHUA XONG CAN FIX
    if (maxHP == 999) {
        rescue = 1;
        cout << "Thong tin cua Hiep si Arthur - ng chien thang tat ca de cuu cong chua: " << endl;
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
    }
    else {
        int index;
        for (index = 0; index < Num_Event; index++) {
            int HP_before = HP;
            // THEO DOI CAC SU KIEN
            cout << "Su kien " << index + 1 << ": Ma su kien " << CacSuKien[index] << endl;
            // MO TA 1
            if (CacSuKien[index] == 0) {
                rescue = 1; // CUU DUOC, CHAM DUT CHUONG TRINH 
                cout << "Giai cuu cong chua thanh cong (MaSK = 0)" << endl;
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                break;
            }

            // MO TA 2 - GAP MADBEAR, BANDIT, LORDLUPIN, ELF TROLL (DA BAO GOM MO TA 11)
            else if ((CacSuKien[index] == 1) || (CacSuKien[index] == 2) || (CacSuKien[index] == 3) || (CacSuKien[index] == 4) || (CacSuKien[index] == 5)) {
                if (!(songuyento(maxHP))) {
                    int LevelO = Level(index + 1);
                    if (level > LevelO) {
                        level += 1;
                        if (level > 10) {
                            level = 10;
                        }
                        // HIEN THI THONG TIN
                        if (index != Num_Event - 1) {
                            cout << "Thong tin cua Hiep si sau su kien thu " << index + 1 << " la: " << endl;
                            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                        }
                    }
                    else if (level < LevelO) {
                        int damage = BaseDamage12345(CacSuKien[index]) * LevelO * 10;
                        HP -= damage;
                        // HP < 0, SU DUNG PHOENIX DOWN
                        if (HP < 0) {
                            if (phoenixdown >= 1) {
                                HP = maxHP;
                                phoenixdown -= 1;
                                // HIEN THI THONG TIN
                                if (index != Num_Event - 1) {
                                    cout << "Thong tin cua Hiep si sau su kien thu " << index + 1 << " la: " << endl;
                                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);                                    
                                }
                            }
                            else {
                                rescue = 0;
                                break;
                            }
                        }
                        else {
                            // HIEN THI THONG TIN
                            if (index != Num_Event - 1) {
                                cout << "Thong tin cua Hiep si sau su kien thu " << index + 1 << " la: " << endl;
                                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);                                
                            }
                        }
                    }
                    else {
                        // HIEN THI THONG TIN
                        if (index != Num_Event - 1) {
                            cout << "Thong tin cua Hiep si sau su kien thu " << index + 1 << " la: " << endl;
                            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                        }
                    }
                }
                // MO TA 11 - HP LA SNT
                else {
                    level += 1;
                    if (level > 10) {
                        level = 10;
                    }
                    // HIEN THI THONG TIN
                    if (index != Num_Event - 1) {
                        cout << "Thong tin cua Hiep si Lancelot sau su kien thu " << index + 1 << " la: " << endl;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    }
                }
            }

            // MO TA 3 - GAP SHAMAN (DA BAO GOM MO TA 11)
            else if (CacSuKien[index] == 6) {
                if (!(songuyento(maxHP))) {
                    // NEU DANG LA TI HON HAY ECH
                    if(tihon != -1 || ech != -1) {
                        // HIEN THI THONG TIN
                        if (index != Num_Event - 1) {
                            cout << "Thong tin cua Hiep si sau su kien thu " << index + 1 << " la: " << endl;
                            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                            continue;
                        }
                        else {
                            if ((tihon == 1 || tihon == 2) || (ech == 1 || ech == 2)) {
                                break;
                            }
                        }
                    }
                    else {
                        int LevelO = Level(index + 1);
                        if (level > LevelO) {
                            level += 2;
                            if (level > 10) {
                                level = 10;
                            }
                            // HIEN THI THONG TIN
                            if (index != Num_Event - 1) {
                                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                            }
                        }
                        else if (level < LevelO) {
                            if (HP < 5) {
                                HP = 1;
                            }
                            else {
                                HP = HP / 5;
                            }
                            tihon += 1;
                            // NEU CO REMEDY
                            if (remedy >= 1) {
                                HP = HP_before;
                                remedy -= 1;
                                tihon = -1;
                            }
                            // HIEN THI THONG TIN
                            if (index != Num_Event - 1) {
                                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                            }
                        }
                        else {
                            // HIEN THI THONG TIN
                            if (index != Num_Event - 1) {
                                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                            }
                        }
                    }
                }
                // MO TA 11
                else {
                    level += 2;
                    if (level > 10) {
                        level = 10;
                    }
                    // HIEN THI THONG TIN
                    cout << "Thong tin cua Hiep si Lancelot sau su kien thu " << index + 1 << " la: " << endl;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
            }

            // MO TA 4 - GAP SIREN VAJSH (DA BAO GOM MO TA 11)
            else if (CacSuKien[index] == 7) {
                if (!(songuyento(maxHP))) {
                    if (tihon != -1 || ech != -1) {
                        // HIEN THI THONG TIN
                        cout << "Thong tin cua Hiep si sau su kien thu " << index + 1 << " la: " << endl;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                        continue;
                    }
                    level_before_ech = level;
                    int LevelO = Level(index + 1);
                    if (level > LevelO) {
                        level += 2;
                        if (level > 10) {
                            level = 10;
                        }
                        // HIEN THI THONG TIN
                        cout << "Thong tin cua Hiep si sau su kien thu " << index + 1 << " la: " << endl;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    }
                    else if (level < LevelO) {
                        ech++;
                        // NEU CO MAIDENKISS, SU DUNG, ECH -> NGUOI, LEVEL -> LEVEL TRUOC KHI ECH
                        if (maidenkiss >= 1) {
                            ech = -1;
                            maidenkiss--;
                            level = level_before_ech;
                        }

                        // HIEN THI THONG TIN
                        cout << "Thong tin cua Hiep si sau su kien thu " << index + 1 << " la: " << endl;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    }
                    else {
                        // HIEN THI THONG TIN
                        cout << "Thong tin cua Hiep si sau su kien thu " << index + 1 << " la: " << endl;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    }
                }
                // MO TA 11
                else {
                    level += 2;
                    if (level > 10) {
                        level = 10;
                    }
                    // HIEN THI THONG TIN
                    cout << "Thong tin cua Hiep si Lancelot sau su kien thu " << index + 1 << " la: " << endl;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
            }

            // MO TA 5 - NHAT DUOC MUSHMARIO
            else if (CacSuKien[index] == 11) {
                int n1 = ((level + phoenixdown) % 5 + 1) * 3;
                //  TINH TONG N1 SO LON NHAT LE CO 2 CHU SO
                int s1 = 0;
                for (int j = 99, n = 1; (j > 0) && (n <= n1); j = j - 2, n++) {
                    s1 += j;
                }
                HP = HP + (s1 % 100);

                // TANG LEN SO NGUYEN TO GAN NHAT LON HON
                int uoc, souoc, songuyentogannhat;
                bool check = true;
                for (int j = HP + 1; (j < 2 * HP) && check; j++) {
                    souoc = 0;
                    bool check1 = true;
                    for (uoc = 1; (uoc <= j) && check1; uoc++) {
                        if (j % uoc == 0) {
                            souoc += 1;
                        }
                        if (souoc > 2) {
                            check1 = false;
                        }
                    }
                    if ((uoc - 1) == j) {
                        songuyentogannhat = j;
                        check = false;
                    }
                }
                HP = songuyentogannhat;
                if (HP > maxHP) {
                    HP = maxHP;
                }
                // HIEN THI THONG TIN
                cout << "Thong tin cua Hiep si sau su kien thu " << index + 1 << " la: " << endl;
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            }

            // MO TA 6 - NHAT DUOC FIBONACCI MUSHFIBO
            else if (CacSuKien[index] == 12) {
                cout << "HP " << HP << endl;
                if (HP == 1) {
                    continue;
                }
                else {
                    //fibonacci, so fibo dau tien la 0, tip theo la 1, 1, 2, 3, ...
                    int a, b = 0, c = 1;
                    bool check = true;
                    while (check) {
                        a = b;
                        b = c;
                        c = b + a;
                        if (c >= HP) {
                            check = false;
                        }
                    }
                    HP = b;
                    // HIEN THI THONG TIN
                    cout << "Thong tin cua Hiep si sau su kien thu " << index + 1 << " la: " << endl;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
            }

            // MO TA 8 - NHAT DUOC REMEDY || MAIDENKISS || PHOENIXDOWN
            else if (CacSuKien[index] == 15 || CacSuKien[index] == 16 || CacSuKien[index] == 17) {
                if (CacSuKien[index] == 15) {
                    remedy += 1;
                    if (remedy > 99) {
                        remedy = 99;
                    }
                }
                else if (CacSuKien[index] == 16) {
                    maidenkiss += 1;
                    if (maidenkiss > 99) {
                        maidenkiss = 99;
                    }
                }
                else {
                    phoenixdown += 1;
                    if (phoenixdown > 99) {
                        phoenixdown = 99;
                    }
                }
            }

            // MO TA 9 - GAP ASCLEPIUS (19) - TANG TUI DO CHUA REMEDY, MAIDENKISS, PHOENIXDOWN (XONG)
            else if (CacSuKien[index] == 19) {
                if (meet_asclepius == 0) {
                    meet_asclepius++;
                    // LAY DATA TU FILE 
                    string trong;
                    int r1, c1;
                    int Thuoc[1024][1024];
                    fstream thuoc (File[1]);
                    thuoc >> r1 >> c1;
                    getline(thuoc, trong);
                    for (int i = 0; i < r1; i++) {
                        for (int j = 0; j < c1; j++) {
                            thuoc >> Thuoc[i][j];
                        }
                    }
                    thuoc.close();
                    for (int i = 0; i < r1; i++) {
                        for (int j = 0; j < c1; j++) {
                            cout << Thuoc[i][j] << " ";
                        }
                        cout << endl;
                    }
                    // END LAY DATA TU FILE
                    
                    // XU LI THONG TIN
                    for (int i = 0; i < r1; i++) {
                        int maxthuoc = 0;
                        for (int j = 0; (j < c1) && (maxthuoc < 3) ; j++) {
                            if (Thuoc[i][j] == 16) {
                                remedy++;
                                maxthuoc++;
                                if (remedy > 99) {
                                    remedy = 99;
                                }
                            }
                            else if (Thuoc[i][j] == 17) {
                                maidenkiss++;
                                maxthuoc++;
                                if (maidenkiss > 99) {
                                    maidenkiss = 99;
                                }
                            }
                            else if (Thuoc[i][j] == 18) {
                                phoenixdown++;
                                maxthuoc++;
                                if (phoenixdown > 99) {
                                    phoenixdown = 99;
                                }
                            }
                            //cout << "remedy: " << remedy << " maidenkiss " << maidenkiss << " phoenixdown " << phoenixdown<< endl;
                        }
                    }

                    // HIEN THI THONG TIN
                        if (index != Num_Event - 1) {
                            cout << "Thong tin cua Hiep si sau su kien thu " << index + 1 << " la: " << endl;
                            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                        }
                }
                else {
                    if (index != Num_Event - 1) {
                        cout << "Thong tin cua Hiep si sau su kien thu " << index + 1 << " la: " << endl;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    }
                }
            }

            // MO TA 12 - GAP BOWSER
            else if (CacSuKien[index] == 99) {
                if (songuyento(HP) && (level >= 8) || !(songuyento(HP)) && (level == 10)) {
                    level = 10;
                    cout << "Chien thang Bowser" << endl;
                    cout << "Thong tin cua Hiep si sau su kien thu " << index + 1 << " (chien thang Bowser) la: " << endl;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
                else {
                    rescue = 0;
                    cout << "Khong cuu duoc cong chua" << endl;
                    cout << "Thong tin cua Hiep si sau su kien thu " << index + 1 << " la: " << endl;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    break;
                }
            }

            // MO TA 13 (CHUA XONG)
            else if (CacSuKien[index] == 18) {
                if (meet_merlin != 0) {
                    cout << "Thong tin cua Hiep si sau su kien thu " << index + 1 << " la: " << endl;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    continue;
                }
                meet_merlin++;
                // LAY DATA
                int num_seq;
                string trong;
                string SEQ[1024];
                cout << File[2] << endl;
                fstream phuthuy(File[2]);
                phuthuy >> num_seq; // LAY SO LUONG MON DO TU TUI
                getline(phuthuy, trong);
                for (int i = 0; i < num_seq; i++) {
                    getline(phuthuy, SEQ[i]); // LAY TUNG MON DO
                }
                phuthuy.close();
                // END LAY DATA

                // HIEN THI DATA TU TUI CUA MERLIN
                for (int i = 0; i < num_seq; i++) {
                    cout << SEQ[i] << endl;
                }
                // END HIEN THI DATA TU TUI CUA MERLIN

                // XU LI THONG TIN 
                string str ("Merlin");
                string str1 ("merlin");
                int bangchucai[6] = {109, 101, 114, 108, 105, 110}; // BANG MA ASCII CUA CAC CHU CAI m e r l i n
                
                // DUYET TUNG DATA
                for (int i = 0; i < num_seq; i++) {
                    int sochucai = SEQ[i].length();
                    int t = 0; // USE TO CHECK IF ENOUGH CHAR OF MERLIN IN THE STRING
                    bool check2 ; 
                    bool check = true;
                    // NEU SO LUONG CHU CAI CUA STRING < 6 THI KIEU GI CUNG KHONG CHUA DUOC "merlin"
                    if (SEQ[i].length() < 6) {
                        continue;
                    }
                    // NEU TRONG CHUOI CO XUAT HIEN CUM TU "Merlin" hay "merlin"
                    else if ((SEQ[i].find(str) != string::npos) || (SEQ[i].find(str1) != string::npos)) {
                        HP += 3;
                        cout << "HP sau khi nhan mon do: " << HP << endl;
                        if (HP > maxHP) {
                            HP = maxHP;
                        }
                    }
                    // CAC TRUONG HOP CON LAI
                    else {
                        // CHUYEN TOAN BO SANG CHU THUONG - EASY TO COMPARE AND FIND
                        for (int u = 0; u < sochucai; u++) {
                            SEQ[i][u] = tolower(SEQ[i][u]);
                        }
                        cout << SEQ[i] << endl;
                        // DUYET TUNG THANG TRONG LIST BANG CHU CAI 
                        // NEU TUNG CHU CO MAT TRONG STRING, SE TIEP TUC DUYET SANG CHU KHAC
                        // NEU TUNG CHU HONG CO MAT TRONG STRING THI THOAT RA HAN
                        for (int j = 0; (j < 6) && check; j++) {
                            check2 = true;
                            //cout << "bangchucai[j] = " << bangchucai[j] << endl;
                            for (int k = 0; (k < sochucai) && check2; k++) {
                                //cout << "SEQ[i][k]" << SEQ[i][k] << endl;
                                if (bangchucai[j] == SEQ[i][k]) {
                                    t++;
                                    cout << "t " << t << endl;
                                    check2 = false;
                                }
                                else {
                                    if (k == sochucai - 1) {
                                        check = false;
                                        check2 = false;
                                    }
                                }
                            }
                        }
                        if (t == 6) {
                            HP += 2;
                            //cout << "HP sau khi nhan mon do: " << HP << endl;
                            if (HP > maxHP) {
                                HP = maxHP;
                            }
                        }
                    }
                }
                cout << "Thong tin cua Hiep si sau su kien thu " << index + 1 << " la: " << endl;
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            }

            // MO TA 7 - NHAT DUOC NAM MA MUSHGHOST (TAM XONG)
            else {
                // LAY THONG TIN LOAI NAM CAN DUNG DE XU LI, THU TU, BO 
                int NamID[1024], NumNam;
                cutnumber(CacSuKien[index], NamID, NumNam);
                /*cout << "Number of Nam " << NumNam << endl;
                cout << "Cac loai nam la: ";
                for (int i = 0; i < NumNam; i++) {
                    cout << NamID[i] << " ";
                }
                cout << endl;*/
                // END LAY THONG TIN LOAI NAM 

                // GET DATA FROM FILE
                int num_seq;
                int SEQ[1024];
                int SEQ_process[1024];
                string seq;
                fstream mush(File[0]);
                mush >> num_seq;
                getline(mush, seq);
                getline(mush, seq);
                mush.close();

                /*istringstream iss (seq);
                for (int i = 0; i < num_seq; i++) {
                    int val;
                    getline(iss, val, ',');
                }*/
                // END GET THE DATA

                // PROCESS
                Get_Seq(seq, SEQ, num_seq);
                cout << "Number of sequence: " << num_seq << endl;
                cout << "The sequence is: ";
                for (int i = 0; i < num_seq; i++) {
                    cout << SEQ[i] << " ";
                }
                cout << endl;

                // XU LI TUNG LOAI NAM (CHAY TEST CASE CHUA DUNG)
                for (int i = 0; i < NumNam; i++) {
                    cout << "Nam ID la: " << NamID[i] << endl;
                    if (NamID[i] == 1) {
                        int maxi = num_seq - 1;
                        int max = SEQ[num_seq - 1];
                        int mini = num_seq - 1;
                        int min = SEQ[num_seq - 1];
                        for (int i = num_seq - 2; i >= 0; i--) {
                            if (SEQ[i] > max) {
                                maxi = i;
                                max = SEQ[i];
                            }
                            if (SEQ[i] < min) {
                                mini = i;
                                min = SEQ[i];
                            }
                        }
                        cout << "So lon nhat la " << max << " co index lon nhat la " << maxi << endl;
                        cout << "So nho nhat la " << min << " co index lon nhat la " << mini << endl;
                        HP = HP - (maxi + mini);
                        if (HP > maxHP) {
                            HP = maxHP;
                        }
                        cout << "Thong tin cua Hiep si sau khi gap Nam la " << NamID[i] << endl;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    }
                    if (NamID[i] == 2) {
                        int mtx, mti;
                        //CheckMountain(SEQ, num_seq, mtx, mti);
                        if (CheckMountain(SEQ, num_seq, mtx, mti)) {
                            cout << "Gia tri cua dinh nui cua day so dang nui la " << mtx << " co index la " << mti << endl;
                        }
                        else {
                            mtx = -2;
                            mti = -3;
                            cout << "Gia tri cua dinh nui cua day so hong co dang nui la " << mtx << " co index la " << mti << endl;
                        }
                        HP = HP - (mtx + mti);
                        if (HP > maxHP) {
                            HP = maxHP;
                        }
                        cout << "Thong tin cua Hiep si sau khi gap Nam la " << NamID[i] << endl;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    }
                    if (NamID[i] == 3) {
                        // Xu li day so 
                        cout << "Sequence sau khi bien doi la: ";
                        for (int i = 0; i < num_seq; i++) {
                            if (SEQ[i] < 0) {
                                //SEQ_process[i] = -SEQ[i];
                                SEQ_process[i] = (17 * (-SEQ[i]) + 9)%257;
                            }
                            else {
                                SEQ_process[i] = (17 * SEQ[i] + 9)%257;
                            }
                            cout << SEQ_process[i] << " ";
                        }
                        cout << endl;
                        // Vi tri dau so lon nhat va nho nhat
                        int min = SEQ_process[0], mini2 = 0;
                        int max = SEQ_process[0], maxi2 = 0;
                        for (int i = 0; i < num_seq; i++) {
                            if (SEQ_process[i] > max) {
                                max = SEQ_process[i];
                                maxi2 = i;
                            }
                            if (SEQ_process[i] < min) {
                                min = SEQ_process[i];
                                mini2 = i;
                            }
                        }
                        cout << "So lon nhat la " << max << " co index nho nhat la " << maxi2 << endl;
                        cout << "So nho nhat la " << min << " co index nho nhat la " << mini2 << endl;
                        HP = HP - (maxi2 + mini2);
                        if (HP > maxHP) {
                            HP = maxHP;
                        }
                        cout << "Thong tin cua Hiep si sau khi gap Nam la " << NamID[i] << endl;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    }
                    if (NamID[i] == 4) {
                        // Xu li day so 
                        cout << "Sequence sau khi bien doi la: ";
                        for (int i = 0; i < num_seq; i++) {
                            if (SEQ[i] < 0) {
                                //SEQ_process[i] = -SEQ[i];
                                SEQ_process[i] = (17 * (-SEQ[i]) + 9)%257;
                            }
                            else {
                                SEQ_process[i] = (17 * SEQ[i] + 9)%257;
                            }
                            cout << SEQ_process[i] << " ";
                        }
                        cout << endl;

                        // SO LON NHAT TRONG SEQUENCE
                        int max = SEQ_process[0];
                        int max2_3x = -99999999, max2_3i = 0; // CHON MAX2 BAN DAU LA GIA TRI NHO NHAT
                        for (int i = 1; i < 3; i++) {
                            if (SEQ_process[i] > max) {
                                max = SEQ_process[i];
                            }
                        }
                        // SO LON THU HAI TRONG SEQUENCE
                        for (int i = 0; i < 3; i++) {
                            if ((SEQ_process[i] > max2_3x) && (SEQ_process[i] != max)) {
                                max2_3x = SEQ_process[i];
                                max2_3i = i;
                            }
                        }
                        if (max2_3x == -99999999) {
                            max2_3x = -5;
                            max2_3i = -7;
                        }
                        cout << "So lon thu 2 cua day so la " << endl;
                        cout << "max2_3x " << max2_3x << " " << "max2_3i " << max2_3i << endl;
                        HP = HP - (max2_3x + max2_3i);
                        if (HP > maxHP) {
                            HP = maxHP;
                        }

                        // CHECK VI TRI DAU TIEN CUA SO LON THU 2 TRONG 3 SO DAU TIEN CUA SEQUENCE
                        /*for (int i = 0; i < 3; i++) {
                            if (max2_3x == SEQ_process[i]) {
                                max2_3i = i;
                                break;
                            }
                            if (i == 2) {
                                max2_3x = -5;
                                max2_3i = -7;
                            }
                        }
                        cout << "So lon nhat cua day so la " << max << endl;
                        cout << "So lon thu 2 cua day so la " << max2 << endl;
                        cout << "max2_3x " << max2_3x << " " << "max2_3i " << max2_3i << endl;
                        HP = HP - (max2_3x + max2_3i);
                        if (HP > maxHP) {
                            HP = maxHP;
                        }*/
                        cout << "Thong tin cua Hiep si sau khi gap Nam la " << NamID[i] << endl;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    }
                }
            }

            // MO TA 3.1
            // XU LI TI HON
            if (tihon == 3) {
                tihon = -1;
                HP *= 5;
                if (HP > maxHP) {
                    HP = maxHP;
                }
            }
            // MO TA 3.1
            // XU LI BIEN THANH TIHON
            if (tihon != -1) {
                tihon++;
                cout << "tihon: " << tihon << endl;
                // NEU NHAT DUOC REMEDY OR PHOENIXDOWN TREN DUONG CUU CONG CHUA
                if ((HP > 0) && (remedy >= 1)) {
                    HP *= 5;
                    remedy -= 1;
                    tihon = -1;
                }
                if ((HP <= 0) && (tihon <= 3)) {
                    if (phoenixdown >= 1) {
                        phoenixdown -= 1;
                        HP = maxHP;
                        tihon = -1;
                    }
                    else {
                        rescue = 0;
                        cout << "Khong cuu duoc cong chua" << endl;
                        cout << "Thong tin cua Hiep si sau su kien thu " << index + 1 << " la: " << endl;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                        break;
                    }
                }
            }
            // MO TA 4.1
            // XU LI BIEN THANH ECH
            if (ech == 3) {
                ech = -1;
                level = level_before_ech;
            }
            // MO TA 4.1
            // XU LI BIEN THANH ECH
            if (ech != -1) {
                ech++;
                cout << "ech: " << ech << endl;
                // NEU NHAT DUOC MAIDENKISS HOAC PHOENIXDOWN TREN DUONG CUU CONG CHUA
                if ((HP > 0) && (maidenkiss >= 1)) {
                    level = level_before_ech;
                    maidenkiss -= 1;
                    ech = -1;
                }
                if ((HP <= 0) && (ech <= 3)) {
                    if (phoenixdown >= 1) {
                        HP = maxHP;
                        ech = -1;
                    }
                    else {
                        rescue = 0;
                        cout << "Khong cuu duoc cong chua" << endl;
                        cout << "Thong tin cua Hiep si sau su kien thu " << index + 1 << " la: " << endl;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                        break;
                    }
                }
            }
        }
        // SO SANH INDEX VOI NUM_EVENT LA BOI VI INDEX DA DUOC INCREASE VA SO SANH VOI DIEU KIEN TRONG VONG LAP
        if ((HP > 0) && (rescue = -1) && (index == Num_Event)) {
            rescue = 1;
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
        }
        if (HP <= 0) {
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
        }
    }
}