#include "Database.hpp"

void Database::addStudent(const std::string &name, const std::string &surname, const std::string &adress,
                          const int &index, const std::string &PESEL, const Sex &sex, const Position &position) noexcept
{
    database_.push_back(std::make_shared<Student>(Student{name, surname, adress, index, PESEL, sex, position}));
}

void Database::addEmployee(const std::string &name, const std::string &surname, const std::string &adress,
                           const float &salary, const std::string &PESEL, const Sex &sex,
                           const Position &position) noexcept
{
    database_.push_back(std::make_shared<Employee>(Employee{name, surname, adress, salary, PESEL, sex, position}));
}

std::string Database::returnRecordsAsString()
{
    std::stringstream sstream;
    for (const auto &record : database_)
    {
        putRecordInSstream(sstream, record);
    }
    return sstream.str();
}

std::string Database::returnRecordsWithGivenSurname(std::string surname)
{
    std::stringstream sstream;
    for (const auto &record : database_)
    {
        if (record->getSurname() == surname)
        {
            putRecordInSstream(sstream, record);
            break;
        }
    }
    return sstream.str();
}

std::string Database::returnRecordWithGivenPesel(std::string pesel)
{
    std::stringstream sstream;
    for (const auto &record : database_)
    {
        if (record->getPESEL() == pesel)
        {
            putRecordInSstream(sstream, record);
            break;
        }
    }
    return sstream.str();
}

std::vector<std::shared_ptr<Person>> Database::findBySurname(const std::string &surname) const noexcept
{
    std::vector<std::shared_ptr<Person>> tempVec;
    for (const auto &el : database_)
    {
        if (el->getSurname() == surname)
        {
            auto tempPtr = el;
            tempVec.push_back(tempPtr);
        }
    }
    return tempVec;
}

std::shared_ptr<Person> Database::findByPESEL(const std::string &PESEL) const noexcept
{
    auto tempIter =
        std::find_if(begin(database_), end(database_), [&PESEL](const auto el) { return el->getPESEL() == PESEL; });
    if (tempIter != end(database_))
    {
        return *(tempIter);
    }
    else
    {
        return nullptr;
    }
}

void Database::sortBySurname() noexcept
{
    std::sort(begin(database_), end(database_),
              [](auto lhs, auto rhs) { return lhs->getSurname() < rhs->getSurname(); });
}

void Database::sortByPESEL() noexcept
{
    std::sort(begin(database_), end(database_), [](auto lhs, auto rhs) { return lhs->getPESEL() < rhs->getPESEL(); });
}

void Database::sortBySalary() noexcept
{
    std::sort(begin(database_), end(database_), [](auto lhs, auto rhs) { return lhs->getSalary() < rhs->getSalary(); });
}

std::string Database::returnEmployeesSortedBySalary()
{
    std::vector<std::shared_ptr<Person>> ret{};
    for (const auto &record : database_)
    {
        if (record->getPosition() == Position::Employee)
        {
            ret.push_back(record);
        }
    }
    std::sort(begin(ret), end(ret), [](auto lhs, auto rhs) { return lhs->getSalary() < rhs->getSalary(); });
    std::stringstream sstream;
    for (const auto &record : ret)
    {
        putRecordInSstream(sstream, record);
    }
    return sstream.str();
}

bool Database::checkIfGivenIndexExist(const int &index)
{
    for (const auto &record : database_)
    {
        if (record->getPosition() == Position::Student and record->getIndex() == index)
        {
            return true;
        }
    }
    return false;
}

bool Database::removeByIndex(const int &index) noexcept
{
    if (database_.size() == 0)
    {
        return false;
    }
    database_.erase(
        std::find_if(begin(database_), end(database_), [&index](const auto el) { return el->getIndex() == index; }));
    return true;
}

bool Database::modifySalary(const std::string &PESEL, const float &newSalary) noexcept
{
    std::shared_ptr<Person> tempPtr = findByPESEL(PESEL);
    if (tempPtr != nullptr && tempPtr->getPosition() == Position::Employee)
    {
        tempPtr->setSalary(newSalary);
        return true;
    }
    else
    {
        return false;
    }
}

bool Database::validatePESEL(const std::string &PESEL) const noexcept
{
    auto tempValidator = std::make_unique<PESELValidator>();
    return tempValidator->validatePESEL(PESEL);
}

void Database::loadToJson() noexcept
{
    nlohmann::json data;
    std::ifstream inputFile("database.json");
    inputFile >> data;
    for (const auto &person : data)
    {
        const Position position = person.at("position").get<Position>();
        if (position == Position::Student)
        {
            const int index = person.at("index").get<int>();
            addStudent(person.at("name").get<std::string>(), person.at("surname").get<std::string>(),
                       person.at("address").get<std::string>(), index, person.at("PESEL").get<std::string>(),
                       person.at("sex").get<Sex>(), position);
        }
        else if (position == Position::Employee)
        {
            const float salary = person.at("salary").get<float>();
            addEmployee(person.at("name").get<std::string>(), person.at("surname").get<std::string>(),
                        person.at("address").get<std::string>(), salary, person.at("PESEL").get<std::string>(),
                        person.at("sex").get<Sex>(), position);
        }
    }
}

void Database::saveToJson() const noexcept
{
    nlohmann::json single;
    nlohmann::json data;
    std::ofstream outputFile("database.json");

    for (const auto &person : database_)
    {
        toJson(single, *person);
        data.push_back(single);
    }
    outputFile << data;
    outputFile.close();
}

void Database::generateData(const int &n) noexcept
{
    auto tempGenerator = std::make_unique<RecordGenerator>();
    for (int i = 0; i < n; i++)
    {
        database_.push_back(tempGenerator->generateRandomRecord());
    }
}

std::shared_ptr<Person> Database::getPtrToRecord(const int &pos) const noexcept
{
    return database_.at(pos);
}

void Database::putRecordInSstream(std::stringstream& sstream, const std::shared_ptr<Person>& record) const noexcept
{
    sstream << "Name: " << record->getName() << std::endl;
    sstream << "Surname: " << record->getSurname() << std::endl;
    sstream << "PESEL: " << record->getPESEL() << std::endl;
    if (static_cast<bool>(record->getSex()))
    {
        sstream << "Sex: female" << std::endl;
    }
    else
    {
        sstream << "Sex: male" << std::endl;
    }
    sstream << "Address: " << record->getAddress() << std::endl;
    if (static_cast<bool>(record->getPosition()))
    {
        sstream << "Position: Employee" << std::endl;
        sstream << "Salary: " << record->getSalary() << std::endl;
        sstream << std::endl;
    }
    else
    {
        sstream << "Position: Student" << std::endl;
        sstream << "Index: " << record->getIndex() << std::endl;
        sstream << std::endl;
    }
}

void Database::toJson(nlohmann::json &j, Person &person) const noexcept
{
    j = nlohmann::json{{"name", person.getName()},       {"surname", person.getSurname()},
                       {"address", person.getAddress()}, {"index", person.getIndex()},
                       {"salary", person.getSalary()},   {"PESEL", person.getPESEL()},
                       {"sex", person.getSex()},         {"position", person.getPosition()}};
}
