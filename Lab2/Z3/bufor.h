#ifndef BUFOR_H
#define BUFOR_H
class Bufor {
    private:
        int *tab;
        unsigned s;
        unsigned iterFirstFree;
    public:
        Bufor();
        Bufor(unsigned tabSize);
        virtual ~Bufor() { delete[] tab; }
        virtual void add (int value);
        virtual double calculate() = 0;
        unsigned getIndex () { return iterFirstFree; }
        unsigned getSize () { return s; }
        int getTab (unsigned i) { return tab[i]; }
        int getFirst () { return tab[iterFirstFree - 1]; }
        void setFirst (int value) { iterFirstFree = value; }
        void setTab (unsigned iter_at, int value) { tab[iter_at] = value; }
        void show ();
};
#endif // !BUFOR_H