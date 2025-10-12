#include <ostream>
#include <iostream>

namespace Mark {
    template<typename Tp>
    const char* mark_to_string(Tp& test);

    const char* veryGood{ "veryGood" }, \
        * good{ "good" }, * satisfyngly{ "satisfyngly" }, \
        * notSatisfyngly{ "not satisfyngly" }, \
        * notCorrectFormat{ "not correct format" };

    enum Format { Russan, English };

    class Test {
    private:
        int _mark;
        Format _format;
    public:
        int getMark(void) { return _mark; }
        Format getFormat(void) { return _format; }
        Test(int mark, Format format) : \
            _mark{ mark }, _format{ format } {}
        friend const char* mark_to_string<Test>(Test& test);
    };
    class Exam : public Test {
    public:
        Exam(int mark, Format format) : \
            Test{ mark, format } {}
        friend const char* mark_to_string<Exam>(Exam& test);
    };
    class FinalExam : public Exam {
    public:
        FinalExam(int mark, Format format) : \
            Exam{ mark, format } {}
        friend const char* mark_to_string<FinalExam>(FinalExam& test);
    };
    class Probation : public FinalExam {
    public:
        Probation(int mark, Format format) : \
            FinalExam{ mark, format } {}
        friend const char* mark_to_string<Probation>(Probation& test);
    };

    template<typename Tp>
    const char* mark_to_string(Tp& test) {
        const int mark{ test.getMark() };
        switch (test.getFormat()) {
        case Russan:
            switch (mark) {
            case 5: case '5':
                return veryGood;
            case 4: case '4':
                return good;
            case 3: case '3':
                return satisfyngly;
            case 2: case '2':
                return notSatisfyngly;
            default: return notCorrectFormat;
            }
        case English:
            switch (mark) {
            case 'A': case 'a':
            case 'B': case 'b':
                return veryGood;
            case 'C': case 'c':
            case 'D': case 'd':
                return good;
            case 'E': case 'e':
                return satisfyngly;
            case 'F': case 'f':
                return notSatisfyngly;
            default: return notCorrectFormat;
            }
        default:
            return notCorrectFormat;
        }
    }

    std::ostream& operator<<(std::ostream& out, Test& test) {
        out << "Mark test's is " << mark_to_string(test) << std::endl;
        return out;
    }

    std::ostream& operator<<(std::ostream& out, Exam& exam) {
        out << "Mark exam's is " << mark_to_string(exam) << std::endl;
        return out;
    }
    std::ostream& operator<<(std::ostream& out, FinalExam& finalExam) {
        out << "Mark final exam's is " << mark_to_string(finalExam) << std::endl;
        return out;
    }
    std::ostream& operator<<(std::ostream& out, Probation& probation) {
        out << "Mark probation's is " << mark_to_string(probation) << std::endl;
        return out;
    }
}
int main(void) {
    Mark::Test test1{ 5, Mark::Russan }, test2{ 'A', Mark::English };
    Mark::Exam exam1{ '4', Mark::Russan }, exam2{ 'c', Mark::English };
    Mark::FinalExam finalExam1{ '3', Mark::Russan }, \
        finalExam2{ 'e', Mark::English };
    Mark::Probation probation1{ 2, Mark::Russan }, \
        probation2{ 'F', Mark::English };
    std::cout << test1 << test2 << exam1 << \
        exam2 << finalExam1 << finalExam2 << \
        probation1 << probation2;
    return 0;
}
