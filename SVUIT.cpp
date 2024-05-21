#include <string>
#include <iostream>
#include <vector>
using namespace std;

class SVUIT {
protected:
    int MSSV, Tc, Diem;
    string ten, diachi;

public:
    SVUIT(int MSSV, int Tc, int Diem, string ten, string diachi)
        : MSSV(MSSV), Tc(Tc), Diem(Diem), ten(ten), diachi(diachi) {}

  
    virtual bool XetTotNghiep() {
    
        return false;
    }

    virtual string GetTen() const { return ten; }
};
class SVDH : public SVUIT {
private:
    int DiemLV;
    string TenLV;

public:
    SVDH(int MSSV, int Tc, int Diem, string ten, string diachi, int DiemLV, string tenLV)
        : SVUIT(MSSV, Tc, Diem, ten, diachi), DiemLV(DiemLV), TenLV(tenLV) {}

    bool XetTotNghiep() override {
        if (Tc >= 170 && Diem >= 5 && DiemLV >= 5) {
            return true;
        }
        else {
            return false;
        }
    }

    string GetTen() const override { return ten; }
};

class SVCD : public SVUIT {
private:
    int DiemTN;

public:
    SVCD(int MSSV, int Tc, int Diem, string ten, string diachi, int DiemTN) : SVUIT(MSSV, Tc, Diem, ten, diachi), DiemTN(DiemTN) {}

    bool XetTotNghiep() override {
        if (Tc >= 120 && Diem >= 5 && DiemTN >= 5) {
            return true;
        }
        else {
            return false;
        }
    }

    string GetTen() const override { return ten; }
};

int main() {
    string tenx;
    int temp=0;
    int max=0;
    int n; //so luong sinh vien dai hoc
    int m; // so luong sinh vien cao dang
    cout << "nhap so luong sinh vien dai hoc :";
    cin >> n;
    cout << "nhap so luong sinh vien cao dang:";
    cin >> m;
    vector<SVUIT*> list;

    for (int i = 0; i < n; i++) {
        int a; //MSSV
        int b; //Tc
        int c; //Diem
        int d; //diemlv
        string g;
        string ten;
        string x; // dia chi
        cout << "nhap ho ten sinh vien dai hoc: ";
        cin >> ten;
        cin.ignore();
        cout << "nhap MSSV cua sinh vien dai hoc: ";
        cin >> a;
        cout << "nhap so tin chi cua sinh vien dai hoc: ";
        cin >> b;
        cout << "nhap so diem cua sinh vien dai hoc: ";
        cin >> c;
        if(c>max)
        {
            max = c;
            tenx = ten;
        }
        cout << "nhap dia chi cua sinh vien dai hoc: ";
        cin >> x;
        cin.ignore();
        cout << "nhap so diem luan van: ";
        cin >> d;
        cout << "nhap ten luan van: ";
        cin >> g;
        cin.ignore();
        cout << "Ho ten sinh vien: " << ten << endl;
        cout << "Dia chi: " << x << endl;
        cout << "MSSV: " << a << endl;
        cout << "So tin chi: " << b << endl;
        cout << "So diem: " << c << endl;
        cout << "Ten luan van: " << g << endl;
        cout << "So diem luan van: " << d << endl;
        list.push_back(new SVDH(a, b, c, ten, x, d, g));
        if (list[i]->XetTotNghiep()) {
            cout << "Sinh vien " << list[i]->GetTen() << " da tot nghiep." << endl;
        }
        else {
            cout << "Sinh vien " << list[i]->GetTen() << " chua tot nghiep." << endl;
            temp += 1;
        }
    }

    for (int i = n; i < m + n; i++) {
        int a; //MSSV
        int b; //Tc
        int c; //Diem
        int d; //diemlv
        string ten;
        string x; // dia chi
        cout << "nhap ho ten sinh vien cao dang: ";
        cin >> ten;
        cin.ignore();
        cout << "nhap MSSV cua sinh vien cao dang: ";
        cin >> a;
        cout << "nhap so tin chi cua sinh vien cao dang: ";
        cin >> b;
        cout << "nhap so diem cua sinh vien cao dang: ";
        cin >> c;
        if (c > max)
        {
            max = c;
            tenx = ten;
        }
        cout << "nhap dia chi cua sinh vien cao dang: ";
        cin >> x;
        cin.ignore();
        cout << "nhap so diem tong ket: ";
        cin >> d;
        cout << "Ho ten sinh vien: " << ten << endl;
        cout << "Dia chi: " << x << endl;
        cout << "MSSV: " << a << endl;
        cout << "So tin chi: " << b << endl;
        cout << "So diem: " << c << endl;
        cout << "Diem tong ket " << d << endl;
        list.push_back(new SVCD(a, b, c, ten, x, d));
        if (list[i]->XetTotNghiep()) {
            cout << "Sinh vien " << list[i]->GetTen() << " da tot nghiep." << endl;
        }
        else {
            cout << "Sinh vien " << list[i]->GetTen() << " chua tot nghiep." << endl;
            temp += 1;
        }
    }
    cout << "So luong sinh vien chua tot nghiep la: " << temp<< endl;
    cout << "Sinh vien co so diem trung binh cao nhat la: " << tenx << " voi so diem la: " << max<< endl;
    return 0;
}
