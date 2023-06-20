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
    // The idea is to use the ASCII value of the digits from 0 to 9 start from 48 -> 57
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
    int n, i = 0;
    stringstream ss(a);
    while (ss >> n){
        ARR[i] = n;
        i++;
    }
    size = i;
}

// GET FILE NAME TO AN ARRAY OF FILE
void Used_File(string a, string(&File)[1024], int(&size)) {
    string arr[1024], n;
    int t = 0;
    int index1 = -1, index2;
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
    //cout << "Dinh " << mtx << " " << "index " << mti << endl;
    
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
        //cout << "Hello" << endl;
        for (int i = 0; (i <= mti - 1) && check; i++) {
            if (arr[i] >= arr[i+1]) {
                check = false;
                // cout << arr[i] << " " << arr[i+1] << endl;
            }
        }
        // Tu dinh nui den ben phai
        for (int i = mti; (i <= socacso - 1) && check; i++) {
            if (arr[i] <= arr[i+1]) {
                check = false;
                // cout << arr[i] << " " << arr[i+1] << endl;
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
    // for (int i = 0; i < Num_Event; i++) {
    //     cout << CacSuKien[i] << " ";
    // }
    // cout << endl;

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
    int index;
    for (index = 0; index < Num_Event; index++) {
        // cout << "sukien " << CacSuKien[index] << endl;
        int HP_before = HP;
        // MO TA 1
        if (CacSuKien[index] == 0) {
            rescue = 1; // CUU DUOC, CHAM DUT CHUONG TRINH 
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            break;
        }

        // MO TA 2 - GAP MADBEAR, BANDIT, LORDLUPIN, ELF TROLL (DA BAO GOM MO TA 11)
        else if ((CacSuKien[index] == 1) || (CacSuKien[index] == 2) || (CacSuKien[index] == 3) || (CacSuKien[index] == 4) || (CacSuKien[index] == 5)) {
            if ((!(songuyento(maxHP))) && !(maxHP == 999)) {
                //cout << CacSuKien[index] << endl;
                int LevelO = Level(index + 1);
                if (level > LevelO) {
                    level += 1;
                    if (level > 10) {
                        level = 10;
                    }
                    // HIEN THI THONG TIN
                    // SAU KHI BI BIEN THANH TI HON, SAU DO 3 SU KIEN, LAI GAP MA SK 6
                    if (index != Num_Event - 1) {
                        if ((tihon == 1) || (tihon == 2)) {
                            tihon++;
                            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                            continue;
                        }
                        else if ((ech == 1) || (ech == 2)) {
                            ech++;
                            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                            continue;
                        }
                        else if ((tihon == 3) || (ech == 3)){
                            if (tihon == 3) {
                                tihon = -1;
                                HP *= 5;
                                if (HP > maxHP) {
                                    HP = maxHP;
                                }
                                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                                continue;
                            }
                            if (ech == 3) {
                                ech = -1;
                                level = level_before_ech;
                                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                                continue;
                            }
                        }  
                        else {
                            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                        }                      
                    }
                }
                else if (level < LevelO) {
                    int damage = BaseDamage12345(CacSuKien[index]) * LevelO * 10;
                    HP -= damage;
                    // HP < 0, SU DUNG PHOENIX DOWN
                    if (HP <= 0) {
                        if (phoenixdown >= 1) {
                            HP = maxHP;
                            phoenixdown -= 1;
                            // cout << "hello" << endl;
                            // HIEN THI THONG TIN
                            if (index != Num_Event - 1) {
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
                        // SAU KHI BI BIEN THANH TI HON, SAU DO 3 SU KIEN, LAI GAP MA SK 6
                        // cout << "rescue thua" << rescue << endl;
                        if (index != Num_Event - 1) {
                            if ((tihon == 1) || (tihon == 2)) {
                                tihon++;
                                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                                continue;
                            }
                            else if ((ech == 1) || (ech == 2)) {
                                ech++;
                                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                                continue;
                            }
                            else if ((tihon == 3) || (ech == 3)){
                                if (tihon == 3) {
                                    tihon = -1;
                                    HP *= 5;
                                    if (HP > maxHP) {
                                        HP = maxHP;
                                    }
                                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                                    continue;
                                }
                                if (ech == 3) {
                                    ech = -1;
                                    level = level_before_ech;
                                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                                    continue;
                                }
                            }  
                            else {
                                // cout << "toi day" << endl;
                                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                                continue;
                            }                      
                            // tihon++;
                            // display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                            // continue;
                        }
                    }
                }
                else {
                    // HIEN THI THONG TIN
                    // SAU KHI BI BIEN THANH TI HON, SAU DO 3 SU KIEN, LAI GAP MA SK 6
                    if (index != Num_Event - 1) {
                        // cout << "rescue hoa " << rescue << endl;
                        if ((tihon == 1) || (tihon == 2)) {
                            tihon++;
                            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                            continue;
                        }
                        else if ((ech == 1) || (ech == 2)) {
                            ech++;
                            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                            continue;
                        }
                        else if ((tihon == 3) || (ech == 3)){
                            if (tihon == 3) {
                                tihon = -1;
                                HP *= 5;
                                if (HP > maxHP) {
                                    HP = maxHP;
                                }
                                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                                continue;
                            }
                            if (ech == 3) {
                                ech = -1;
                                level = level_before_ech;
                                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                                continue;
                            }
                        }  
                        else {
                            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                        }                      
                        // tihon++;
                        // display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                        // continue;
                    }
                }
            }
            // MO TA 11 - ANCELOT HAY VUA ARTHUR
            else {
                level += 1;
                if (level > 10) {
                    level = 10;
                }
                // HIEN THI THONG TIN
                if (index != Num_Event - 1) {
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
            }
        }

        // MO TA 3 - GAP SHAMAN (DA BAO GOM MO TA 11)
        else if (CacSuKien[index] == 6) {
            if ((!(songuyento(maxHP))) && !(maxHP == 999)) {
                // NEU DANG LA TI HON HAY ECH
                //cout << "ti hon " << tihon << endl;
                //cout << "index " << index << endl;
                if(tihon != -1 || ech != -1) {
                    // HIEN THI THONG TIN
                    // SAU KHI BI BIEN THANH TI HON, SAU DO 3 SU KIEN, LAI GAP MA SK 6
                    if (index != Num_Event - 1) {
                        if ((tihon == 1) || (tihon == 2)) {
                            tihon++;
                            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                            continue;
                        }
                        else if ((ech == 1) || (ech == 2)) {
                            ech++;
                            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                            continue;
                        }
                        else {
                            if (tihon == 3) {
                                tihon = -1;
                                HP *= 5;
                                if (HP > maxHP) {
                                    HP = maxHP;
                                }
                                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                                continue;
                            }
                            if (ech == 3) {
                                ech = -1;
                                level = level_before_ech;
                                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                                continue;
                            }
                        }                        
                        // tihon++;
                        // display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                        // continue;
                    }
                    // else {
                    //     if ((tihon == 1 || tihon == 2) || (ech == 1 || ech == 2)) {
                    //         break;
                    //     }
                    //     else {
                    //         if (tihon == 3) {
                    //             tihon = -1;
                    //             HP *= 5;
                    //             if (HP > maxHP) {
                    //                 HP = maxHP;
                    //             }
                    //             continue;
                    //         }
                    //         if (ech == 3) {
                    //             ech = -1;
                    //             level = level_before_ech;
                    //             continue;
                    //         }
                    //     }
                    // }
                }
                // NEU HONG LA TI HON HAY ECH
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
                            // HIEN THI THONG TIN
                            if (index != Num_Event - 1) {
                                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                            }
                            continue;
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
            // MO TA 11 - ANCELOT HAY VUA ARTHUR
            else {
                level += 2;
                if (level > 10) {
                    level = 10;
                }
                // HIEN THI THONG TIN
                if (index != Num_Event - 1) {
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
            }
        }

        // MO TA 4 - GAP SIREN VAJSH (DA BAO GOM MO TA 11)
        else if (CacSuKien[index] == 7) {
            if ((!(songuyento(maxHP))) && !(maxHP == 999)) {
                // NEU DANG LA TI HON HAY ECH
                //cout << "ech " << ech << endl;
                //cout << "index " << index << endl;
                if(tihon != -1 || ech != -1) {
                    // HIEN THI THONG TIN
                    // SAU KHI BI BIEN THANH TI HON, SAU DO 3 SU KIEN, LAI GAP MA SK 6
                    if (index != Num_Event - 1) {
                        if ((tihon == 1) || (tihon == 2)) {
                            tihon++;
                            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                            continue;
                        }
                        else if ((ech == 1) || (ech == 2)) {
                            ech++;
                            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                            continue;
                        }
                        else {
                            if (tihon == 3) {
                                tihon = -1;
                                HP *= 5;
                                if (HP > maxHP) {
                                    HP = maxHP;
                                }
                                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                                continue;
                            }
                            if (ech == 3) {
                                ech = -1;
                                level = level_before_ech;
                                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                                continue;
                            }
                        }                        
                        // tihon++;
                        // display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                        // continue;
                    }
                    // else {
                    //     if ((tihon == 1 || tihon == 2) || (ech == 1 || ech == 2)) {
                    //         break;
                    //     }
                    //     else {
                    //         if (tihon == 3) {
                    //             tihon = -1;
                    //             HP *= 5;
                    //             if (HP > maxHP) {
                    //                 HP = maxHP;
                    //             }
                    //             continue;
                    //         }
                    //         if (ech == 3) {
                    //             ech = -1;
                    //             level = level_before_ech;
                    //             continue;
                    //         }
                    //     }
                    // }
                }
                // NEU HONG LA TI HON HAY ECH
                else {
                    level_before_ech = level;
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
                        ech++;
                        level = 1;
                        // NEU CO MAIDENKISS, SU DUNG, ECH -> NGUOI, LEVEL -> LEVEL TRUOC KHI ECH
                        if (maidenkiss >= 1) {
                            ech = -1;
                            maidenkiss--;
                            level = level_before_ech;
                            // HIEN THI THONG TIN
                            if (index != Num_Event - 1) {
                                // cout << "Hello" << endl;
                                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                            }
                            continue;
                        }
                        // HIEN THI THONG TIN
                        // if (index != Num_Event - 1) {
                        //     cout << "Hello" << endl;
                        //     display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                        // }
                    }
                    else {
                        // HIEN THI THONG TIN
                        if ((index != Num_Event - 1) && (ech != 0)) {
                            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                        }
                    }
                }
            }
            // MO TA 11 - ANCELOT HAY VUA ARTHUR
            else {
                level += 2;
                if (level > 10) {
                    level = 10;
                }
                // HIEN THI THONG TIN
                if (index != Num_Event - 1) {
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
            }
        }

        // MO TA 5 - NHAT DUOC MUSHMARIO - TANG SO NGUYEN TO GAN NHAT LON HON
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
            // SAU KHI BI BIEN THANH TI HON, SAU DO 3 SU KIEN, LAI GAP MA SK 6
            if (index != Num_Event - 1) {
                if ((tihon == 1) || (tihon == 2)) {
                    tihon++;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    continue;
                }
                else if ((ech == 1) || (ech == 2)) {
                    ech++;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    continue;
                }
                else if ((tihon == 3) || (ech == 3)){
                    if (tihon == 3) {
                        tihon = -1;
                        HP *= 5;
                        if (HP > maxHP) {
                            HP = maxHP;
                        }
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                        continue;
                    }
                    if (ech == 3) {
                        ech = -1;
                        level = level_before_ech;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                        continue;
                    }
                }  
                else {
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }                      
                // tihon++;
                // display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                // continue;
            }
        }

        // MO TA 6 - NHAT DUOC FIBONACCI MUSHFIBO
        else if (CacSuKien[index] == 12) {
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
                // SAU KHI BI BIEN THANH TI HON, SAU DO 3 SU KIEN, LAI GAP MA SK 6
                if (index != Num_Event - 1) {
                    if ((tihon == 1) || (tihon == 2)) {
                        tihon++;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                        continue;
                    }
                    else if ((ech == 1) || (ech == 2)) {
                        ech++;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                        continue;
                    }
                    else if ((tihon == 3) || (ech == 3)){
                        if (tihon == 3) {
                            tihon = -1;
                            HP *= 5;
                            if (HP > maxHP) {
                                HP = maxHP;
                            }
                            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                            continue;
                        }
                        if (ech == 3) {
                            ech = -1;
                            level = level_before_ech;
                            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                            continue;
                        }
                    }  
                    else {
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    }                      
                    // tihon++;
                    // display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    // continue;
                }
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
            else if (CacSuKien[index] == 17) {
                phoenixdown += 1;
                if (phoenixdown > 99) {
                    phoenixdown = 99;
                }
            }
            else {
                throw "Event Code is not correct!";
            }
            // DO NOT KNOW IF DISPLAY HERE
            // HIEN THI THONG TIN
            if ((index != Num_Event - 1) && (tihon == -1) && (ech == -1)) {
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            }
        }

        // MO TA 9 - GAP ASCLEPIUS (19) - TANG TUI DO CHUA REMEDY, MAIDENKISS, PHOENIXDOWN (XONG)
        // Thứ tự sự kiện trọng Asclepius như sau: (1) nhặt toàn bộ thuốc -> (2) sử dụng thuốc vừa nhặt nếu có -> (3) kết thúc sự kiện, tiến hành giải ếch.
        else if (CacSuKien[index] == 19) {
            if (meet_asclepius == 0) {
                meet_asclepius += 1;
                // LAY DATA TU FILE 
                string trong;
                int r1 = 0, c1 = 0;
                int Thuoc[1024][1024];
                // cout << File[1] << endl;
                ifstream thuoc (File[1]);
                thuoc >> r1 >> c1;
                // cout << r1 << " " << c1 << endl;
                getline(thuoc, trong);
                for (int i = 0; i < r1; i++) {
                    for (int j = 0; j < c1; j++) {
                        thuoc >> Thuoc[i][j];
                    }
                }
                thuoc.close();
                // END LAY DATA TU FILE
                
                // TEST
                // for (int i = 0; i < r1; i++) {
                //     for (int j = 0; j < c1; j++) {
                //         cout << Thuoc[i][j] << " ";
                //     }
                //     cout << endl;
                // }
                // END TEST 

                // XU LI THONG TIN
                for (int i = 0; i < r1; i++) {
                    int maxthuoc = 0;
                    for (int j = 0; (j < c1) && (maxthuoc < 3) ; j++) {
                        if (Thuoc[i][j] == 16) {
                            remedy += 1;
                            maxthuoc += 1;
                            if (remedy > 99) {
                                remedy = 99;
                            }
                        }
                        else if (Thuoc[i][j] == 17) {
                            maidenkiss += 1;
                            maxthuoc += 1;
                            if (maidenkiss > 99) {
                                maidenkiss = 99;
                            }
                        }
                        else if (Thuoc[i][j] == 18) {
                            phoenixdown += 1;
                            maxthuoc += 1;
                            if (phoenixdown > 99) {
                                phoenixdown = 99;
                            }
                        }
                    }
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

        // MO TA 12 - GAP BOWSER
        else if (CacSuKien[index] == 99) {
            if ((maxHP == 999) || (songuyento(maxHP) && (level >= 8)) || (!(songuyento(maxHP)) && (level == 10))) {
                level = 10;
                // HIEN THI THONG TIN
                // if (index != Num_Event - 1) {
                //     display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                // }
                // HIEN THI THONG TIN
                // SAU KHI BI BIEN THANH TI HON, SAU DO 3 SU KIEN, LAI GAP MA SK 6
                if (index != Num_Event - 1) {
                    if ((tihon == 1) || (tihon == 2)) {
                        tihon++;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                        continue;
                    }
                    else if ((ech == 1) || (ech == 2)) {
                        ech++;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                        continue;
                    }
                    else if ((tihon == 3) || (ech == 3)){
                        if (tihon == 3) {
                            tihon = -1;
                            HP *= 5;
                            if (HP > maxHP) {
                                HP = maxHP;
                            }
                            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                            continue;
                        }
                        if (ech == 3) {
                            ech = -1;
                            level = level_before_ech;
                            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                            continue;
                        }
                    }  
                    else {
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    }                      
                }
            }
            else {
                rescue = 0;
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                break;
            }
        }

        // MO TA 13 - NHAT TRANG BI TRONG TUI DO CUA MERLIN (CHUA XONG)
        else if (CacSuKien[index] == 18) {
            // GAP LAN > 1
            if (meet_merlin != 0) {
                // HIEN THI THONG TIN
                if (index != Num_Event - 1) {
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    continue;
                }
                else {
                    continue;
                }
            }
            meet_merlin++;
            // LAY DATA
            int num_seq;
            string trong;
            string SEQ[1024];
            ifstream phuthuy(File[2]);
            phuthuy >> num_seq; // LAY SO LUONG MON DO TU TUI
            getline(phuthuy, trong);
            for (int i = 0; i < num_seq; i++) {
                getline(phuthuy, SEQ[i]); // LAY TUNG MON DO
            }
            phuthuy.close();
            // END LAY DATA

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
                    //cout << SEQ[i] << endl;
                    // DUYET TUNG THANG TRONG LIST BANG CHU CAI 
                    // NEU TUNG CHU CO MAT TRONG STRING, SE TIEP TUC DUYET SANG CHU KHAC
                    // NEU TUNG CHU HONG CO MAT TRONG STRING THI THOAT RA HAN
                    for (int j = 0; (j < 6) && check; j++) {
                        check2 = true;
                        for (int k = 0; (k < sochucai) && check2; k++) {
                            if (bangchucai[j] == SEQ[i][k]) {
                                t++;
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
                        if (HP > maxHP) {
                            HP = maxHP;
                        }
                    }
                }
            }
            // HIEN THI THONG TIN
            if (index != Num_Event - 1) {
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            }
        }

        // MO TA 7 - NHAT DUOC NAM MA MUSHGHOST (TAM XONG)
        else if (convert_string_int(to_string(CacSuKien[index]).substr(0, 2)) == 13) {
            // LAY THONG TIN LOAI NAM CAN DUNG DE XU LI, THU TU, BO 
            int NamID[1024], NumNam;
            cutnumber(CacSuKien[index], NamID, NumNam);

            // GET DATA FROM FILE
            int num_seq;
            int SEQ[1024];
            int SEQ_process[1024];
            string seq;
            ifstream mush(File[0]);
            mush >> num_seq;
            getline(mush, seq);
            getline(mush, seq);
            mush.close();
            // END GET THE DATA

            // PROCESS
            Get_Seq(seq, SEQ, num_seq);

            // TEST SEQ
            // for (int i = 0; i < num_seq; i++) {
            //     cout << SEQ[i] << " ";
            // }
            // cout << endl;
            // END TEST SEQ

            // XU LI TUNG LOAI NAM (CHAY TEST CASE CHUA DUNG)
            int i;
            for (i = 0; i < NumNam; i++) {
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
                    HP = HP - (maxi + mini);
                    //cout << "HP sau nam 1 (chua so sanh max)" << HP << endl;
                    if (HP > maxHP) {
                        HP = maxHP;
                    }
                    if (HP <= 0) {
                        if (phoenixdown > 0) {
                            phoenixdown -= 1;
                            HP = maxHP;
                        }
                        else {
                            rescue = 0;
                            break;
                        }
                    } 
                }
                if (NamID[i] == 2) {
                    int mtx, mti;
                    // CheckMountain(SEQ, num_seq, mtx, mti);
                    if (!(CheckMountain(SEQ, num_seq, mtx, mti))) {
                        mtx = -2;
                        mti = -3;
                    }
                    HP = HP - (mtx + mti);
                    //out << "HP sau nam 2 (chua so sanh max)" << HP << endl;
                    if (HP > maxHP) {
                        HP = maxHP;
                    }
                    if (HP <= 0) {
                        if (phoenixdown > 0) {
                            phoenixdown -= 1;
                            HP = maxHP;
                        }
                        else {
                            rescue = 0;
                            break;
                        }
                    }
                }
                if (NamID[i] == 3) {
                    // Xu li day so 
                    for (int i = 0; i < num_seq; i++) {
                        if (SEQ[i] < 0) {
                            SEQ_process[i] = (17 * (-SEQ[i]) + 9)%257;
                        }
                        else {
                            SEQ_process[i] = (17 * SEQ[i] + 9)%257;
                        }
                    }
                    //TEST
                    // for (int i = 0; i < num_seq; i++) {
                    //     cout << SEQ_process[i] << " ";
                    // }
                    // cout << endl;
                    //END TEST
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
                    HP = HP - (maxi2 + mini2);
                    // cout << "HP sau nam 3 (chua so sanh max)" << HP << endl;
                    if (HP > maxHP) {
                        HP = maxHP;
                    }
                    if (HP <= 0) {
                        if (phoenixdown > 0) {
                            phoenixdown -= 1;
                            HP = maxHP;
                        }
                        else {
                            rescue = 0;
                            break;
                        }
                    }
                }
                if (NamID[i] == 4) {
                    // Xu li day so 
                    for (int i = 0; i < num_seq; i++) {
                        if (SEQ[i] < 0) {
                            SEQ_process[i] = (17 * (-SEQ[i]) + 9)%257;
                        }
                        else {
                            SEQ_process[i] = (17 * SEQ[i] + 9)%257;
                        }
                    }
                    // TEST
                    // for (int i = 0; i < num_seq; i++) {
                    //     cout << SEQ_process[i] << " ";
                    // }
                    // cout << endl;
                    // END TEST
                    int max = SEQ_process[0];
                    int max2_3x = -99999999, max2_3i = 0; // CHON MAX2 BAN DAU LA GIA TRI NHO NHAT
                    if (num_seq >= 3) {
                        // SO LON NHAT TRONG SEQUENCE
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
                    }
                    else {
                        if (SEQ_process[0] > SEQ_process[1]) {
                            max2_3x = SEQ_process[1];
                            max2_3i = 1;
                        }
                        else if (SEQ_process[0] < SEQ_process[1]) {
                            max2_3x = SEQ_process[0];
                            max2_3i = 0;
                        }
                        else {
                            max2_3x == -99999999;
                            max2_3i = 0;
                        }
                    }
                    // // SO LON NHAT TRONG SEQUENCE
                    // int max = SEQ_process[0];
                    // int max2_3x = -99999999, max2_3i = 0; // CHON MAX2 BAN DAU LA GIA TRI NHO NHAT
                    // for (int i = 1; i < 3; i++) {
                    //     if (SEQ_process[i] > max) {
                    //         max = SEQ_process[i];
                    //     }
                    // }
                    // // SO LON THU HAI TRONG SEQUENCE
                    // for (int i = 0; i < 3; i++) {
                    //     if ((SEQ_process[i] > max2_3x) && (SEQ_process[i] != max)) {
                    //         max2_3x = SEQ_process[i];
                    //         max2_3i = i;
                    //     }
                    // }
                    if (max2_3x == -99999999) {
                        max2_3x = -5;
                        max2_3i = -7;
                    }
                    // cout << max2_3x << " " << max2_3i << endl;
                    HP = HP - (max2_3x + max2_3i);
                    // cout << "HP sau nam 4 (chua so sanh max)" << HP << endl;
                    if (HP > maxHP) {
                        HP = maxHP;
                    }
                    if (HP <= 0) {
                        if (phoenixdown > 0) {
                            phoenixdown -= 1;
                            HP = maxHP;
                        }
                        else {
                            rescue = 0;
                            break;
                        }
                    }
                }
            }
            if (HP < 0) {
                break;
            }
            if (i == NumNam) {
                // HIEN THI THONG TIN
                if (index != Num_Event - 1) {
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                }
            }
        }
        
        // MA SU KIEN BI SAI
        else {
            throw "Event Code is not correct!";
        }

        // MO TA 3.1
        // XU LI TI HON
        if (tihon == 3) {
            tihon = -1;
            HP *= 5;
            if (HP > maxHP) {
                HP = maxHP;
            }
            // HIEN THI THONG TIN
            if ((index != Num_Event - 1) ) {
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            }
        }
        // MO TA 3.1
        // XU LI BIEN THANH TIHON
        if (tihon != -1) {
            tihon++; // SU KIEN THU "tihon" BI BIEN THANH TI HON
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
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    break;
                }
            }
            // HIEN THI THONG TIN
            if ((index != Num_Event - 1) ) {
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            }
        }
        // MO TA 4.1
        // XU LI BIEN THANH ECH
        if (ech == 3) {
            ech = -1;
            level = level_before_ech;
            // HIEN THI THONG TIN
            if ((index != Num_Event - 1) ) {
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            }
        }
        // MO TA 4.1
        // XU LI BIEN THANH ECH
        if (ech != -1) {
            // cout << "Holle" << endl;
            ech++;
            //cout << "ech: " << ech << endl;
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
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    break;
                }
            }
            // HIEN THI THONG TIN
            if ((index != Num_Event - 1) ) {
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            }
        }
    }
    //cout << HP << " " << rescue << " " << index << endl;
    // SO SANH INDEX VOI NUM_EVENT LA BOI VI INDEX DA DUOC INCREASE VA SO SANH VOI DIEU KIEN TRONG VONG LAP
    if ((HP > 0) && (rescue = -1) && (index == Num_Event)) {
        rescue = 1;
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
    }
    if (HP <= 0) {
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
    }
}