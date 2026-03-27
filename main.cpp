
#include <iostream>
#include <string>

using namespace std;

class LoaiXe {
private:
    string maLoai;
    string tenLoai;
    int giaTien;

public:
    void nhap() {
        int chon;

        cout << "Chon loai xe:\n";
        cout << "1. Xe may\n";
        cout << "2. O to\n";
        cout << "Nhap lua chon: ";
        cin >> chon;

        if (chon == 1) {
            maLoai = "XM";
            tenLoai = "Xe may";
            giaTien = 5000;
        }
        else if (chon == 2) {
            maLoai = "OT";
            tenLoai = "O to";
            giaTien = 10000;
        }
        else {
            cout << "Lua chon khong hop le!\n";
            maLoai = "";
            tenLoai = "";
            giaTien = 0;
        }
    }

    int getGiaTien() {
        return giaTien;
    }

    string getTenLoai() {
        return tenLoai;
    }
};

class VeXe {
private:
    string maVe;
    string bienSo;
    LoaiXe loaiXe;

    int gioVao, gioRa;
    int ngayVao, ngayRa;
    int hinhThuc;

public:
    void nhap() {
        cout << "Nhap ma ve: ";
        cin >> maVe;

        cin.ignore();
        cout << "Nhap bien so xe: ";
        getline(cin, bienSo);

        cout << "Nhap thong tin loai xe\n";
        loaiXe.nhap();

        cout << "Chon hinh thuc gui:\n";
        cout << "1. Theo gio\n";
        cout << "2. Theo ngay\n";
        cout << "Nhap lua chon: ";
        cin >> hinhThuc;

        if (hinhThuc == 1) {
            cout << "Nhap gio vao: ";
            cin >> gioVao;
            gioRa = 0;
        }
        else if (hinhThuc == 2) {
            cout << "Nhap ngay vao: ";
            cin >> ngayVao;
            ngayRa = 0;
        }
        else {
            cout << "Lua chon khong hop le!\n";
        }
    }

    void xeRa() {
        if (hinhThuc == 1) {
            do {
                cout << "Nhap gio ra: ";
                cin >> gioRa;

                if (gioRa < gioVao)
                    cout << "Gio ra phai lon hon gio vao!\n";

            } while (gioRa < gioVao);
        }
        else {
            do {
                cout << "Nhap ngay ra: ";
                cin >> ngayRa;

                if (ngayRa < ngayVao)
                    cout << "Ngay ra phai lon hon ngay vao!\n";

            } while (ngayRa < ngayVao);
        }

        cout << "Tien phai tra: " << tinhTien() << " VND\n";
    }

    int tinhTien() {
        if (hinhThuc == 1) {
            int soGio = gioRa - gioVao;
            if (soGio == 0) soGio = 1;
            return soGio * loaiXe.getGiaTien();
        }
        else {
            int soNgay = ngayRa - ngayVao;
            if (soNgay == 0) soNgay = 1;
            return soNgay * loaiXe.getGiaTien() * 5;
        }
    }

    void hienThi() {
        cout << "Ma ve: " << maVe << endl;
        cout << "Bien so: " << bienSo << endl;
        cout << "Loai xe: " << loaiXe.getTenLoai() << endl;

        if (hinhThuc == 1) {
            cout << "Gio vao: " << gioVao << endl;
            cout << "Gio ra: " << gioRa << endl;
        }
        else {
            cout << "Ngay vao: " << ngayVao << endl;
            cout << "Ngay ra: " << ngayRa << endl;
        }

        if ((hinhThuc == 1 && gioRa != 0) || (hinhThuc == 2 && ngayRa != 0))
            cout << "Tien gui xe: " << tinhTien() << endl;

        cout << "----------------------\n";
    }

    string getBienSo() {
        return bienSo;
    }
};

class QuanLyVe {
private:
    VeXe danhSachVe[100];
    int soLuong;

public:
    QuanLyVe() {
        soLuong = 0;
    }

    void themVe() {
        if (soLuong >= 100) {
            cout << "Bai xe da day!\n";
            return;
        }

        cout << "\n--- XE VAO BAI ---\n";
        danhSachVe[soLuong].nhap();
        soLuong++;

        cout << "Them ve thanh cong!\n";
    }

    void hienThiDanhSachVe() {
        if (soLuong == 0) {
            cout << "Khong co xe nao!\n";
            return;
        }

        cout << "\n--- DANH SACH XE ---\n";

        for (int i = 0; i < soLuong; i++) {
            cout << "Xe thu " << i + 1 << endl;
            danhSachVe[i].hienThi();
        }
    }

    void timVe() {
        string bien;
        cin.ignore();
        cout << "Nhap bien so can tim: ";
        getline(cin, bien);

        for (int i = 0; i < soLuong; i++) {
            if (danhSachVe[i].getBienSo() == bien) {
                cout << "Tim thay xe:\n";
                danhSachVe[i].hienThi();
                return;
            }
        }

        cout << "Khong tim thay!\n";
    }

    void xeRa() {
        string bien;
        cin.ignore();
        cout << "Nhap bien so xe ra: ";
        getline(cin, bien);

        for (int i = 0; i < soLuong; i++) {
            if (danhSachVe[i].getBienSo() == bien) {
                cout << "Thong tin xe:\n";
                danhSachVe[i].xeRa();
                for (int j = i; j < soLuong - 1; j++) {
                    danhSachVe[j] = danhSachVe[j + 1];
                }
                soLuong--;

                cout << "Xe da roi bai!\n";
                return;
            }
        }

        cout << "Khong tim thay xe!\n";
    }
};

int main() {
    QuanLyVe ql;
    int chon;

    do {
        cout << "\n===== QUAN LY BAI DO XE =====\n";
        cout << "1. Xe vao bai\n";
        cout << "2. Xe ra bai\n";
        cout << "3. Hien thi danh sach\n";
        cout << "4. Tim xe\n";
        cout << "0. Thoat\n";

        cout << "Chon: ";
        cin >> chon;

        switch (chon) {
        case 1:
            ql.themVe();
            break;
        case 2:
            ql.xeRa();
            break;
        case 3:
            ql.hienThiDanhSachVe();
            break;
        case 4:
            ql.timVe();
            break;
        case 0:
            cout << "Tam biet!\n";
            break;
        default:
            cout << "Sai lua chon!\n";
        }

    } while (chon != 0);

    return 0;
}
