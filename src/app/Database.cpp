#include "Database.hpp"

void Database::addStudent(const std::string &name, const std::string &surname,
                          const std::string &adress, const int &index,
                          const std::string &PESEL, const Sex &sex,
                          const Position &position) noexcept {
  database_.push_back(std::make_shared<Student>(
      Student{name, surname, adress, index, PESEL, sex, position}));
}

void Database::addEmployee(const std::string &name, const std::string &surname,
                           const std::string &adress, const float &salary,
                           const std::string &PESEL, const Sex &sex,
                           const Position &position) noexcept {
  database_.push_back(std::make_shared<Employee>(
      Employee{name, surname, adress, salary, PESEL, sex, position}));
}

void Database::show() const noexcept {
  system("clear");
  std::for_each(begin(database_), end(database_),
                [this](const auto ptr) { printByPtr(ptr); });
}

void Database::printByPtr(const std::shared_ptr<Person> ptr) const noexcept {
  std::cout << "===================================" << std::endl;
  std::cout << "Name: " << ptr->getName() << std::endl;
  std::cout << "Surname: " << ptr->getSurname() << std::endl;
  std::cout << "Adress: " << ptr->getAdress() << std::endl;
  std::cout << "Position: " << ptr->positionPrint[ptr->getPosition()]
            << std::endl;
  switch (ptr->getPosition()) {
  case Position::Student:
    std::cout << "Index: " << ptr->getIndex() << std::endl;
    break;
  case Position::Employee:
    std::cout << "Salary: " << std::fixed << std::setprecision(2)
              << ptr->getSalary() << std::endl;
    break;
  }
  std::cout << "PESEL: " << ptr->getPESEL() << std::endl;
  std::cout << "Sex: " << ptr->sexPrint[ptr->getSex()] << std::endl;
  std::cout << "===================================" << std::endl;
}

std::string Database::returnRecordsAsString() {
  std::stringstream sstream;
  for (const auto &el : database_) {
    sstream << "Name: " << el->getName() << std::endl;
    sstream << "Surname: " << el->getSurname() << std::endl;
    if (static_cast<bool>(el->getSex())) {
      sstream << "Sex: female" << std::endl;
    } else {
      sstream << "Sex: male" << std::endl;
    }
    sstream << "Address: " << el->getAdress() << std::endl;
    if (static_cast<bool>(el->getPosition())) {
      sstream << "Position: Employee" << std::endl;
      sstream << "Salary: " << el->getSalary() << std::endl;
      sstream << std::endl;
    } else {
      sstream << "Position: Student" << std::endl;
      sstream << "Index: " << el->getIndex() << std::endl;
      sstream << std::endl;
    }
  }
  return sstream.str();
}

void Database::showBySurname(const std::string &surname) const noexcept {
  system("clear");
  auto tempVec = findBySurname(surname);
  if (tempVec.size() == 0) {
    std::cout << "No records with given surname found" << std::endl;
  } else {
    std::for_each(begin(tempVec), end(tempVec),
                  [this](const auto ptr) { printByPtr(ptr); });
  }
}

void Database::showByPESEL(const std::string &PESEL) const noexcept {
  system("clear");
  auto ptr = findByPESEL(PESEL);
  if (ptr == nullptr) {
    std::cout << "No records with given PESEL found" << std::endl;
  } else {
    printByPtr(ptr);
  }
}

std::vector<std::shared_ptr<Person>>
Database::findBySurname(const std::string &surname) const noexcept {
  std::vector<std::shared_ptr<Person>> tempVec;
  for (const auto &el : database_) {
    if (el->getSurname() == surname) {
      auto tempPtr = el;
      tempVec.push_back(tempPtr);
    }
  }
  return tempVec;
}

std::shared_ptr<Person>
Database::findByPESEL(const std::string &PESEL) const noexcept {
  auto tempIter =
      std::find_if(begin(database_), end(database_),
                   [&PESEL](const auto el) { return el->getPESEL() == PESEL; });
  if (tempIter != end(database_)) {
    return *(tempIter);
  } else {
    return nullptr;
  }
}

void Database::sortBySurname() noexcept {
  std::sort(begin(database_), end(database_), [](auto lhs, auto rhs) {
    return lhs->getSurname() < rhs->getSurname();
  });
}

void Database::sortByPESEL() noexcept {
  std::sort(begin(database_), end(database_), [](auto lhs, auto rhs) {
    return lhs->getPESEL() < rhs->getPESEL();
  });
}

void Database::sortBySalary() noexcept {
  std::sort(begin(database_), end(database_), [](auto lhs, auto rhs) {
    return lhs->getSalary() < rhs->getSalary();
  });
}

bool Database::removeByIndex(const int &index) noexcept {
  if (database_.size() == 0) {
    std::cout << "No records in database" << std::endl;
    return false;
  }
  database_.erase(
      std::find_if(begin(database_), end(database_), [&index](const auto el) {
        return el->getIndex() == index;
      }));
  return true;
}

bool Database::modifySalary(const std::string &PESEL,
                            const float &newSalary) noexcept {

  std::shared_ptr<Person> tempPtr = findByPESEL(PESEL);
  if (tempPtr != nullptr && tempPtr->getPosition() == Position::Employee) {
    tempPtr->setSalary(newSalary);
    return true;
  } else {
    return false;
  }
}

bool Database::validatePESEL(const std::string &PESEL) const noexcept {
  auto tempValidator = std::make_unique<PESELValidator>();
  return tempValidator->validatePESEL(PESEL);
}

void Database::loadToJson() const noexcept {}

void Database::fromJson(nlohmann::json &j, Person &person) const noexcept {}

void Database::saveToJson() const noexcept {
  nlohmann::json single;
  nlohmann::json data;
  std::ofstream outputFile("database.json");

  for (const auto &person : database_) {
    toJson(single, *person);
    data.push_back(single);
  }
  outputFile << data;
  outputFile.close();
}

void Database::toJson(nlohmann::json &j, Person &person) const noexcept {
  j = nlohmann::json{
      {"name", person.getName()},     {"surname", person.getSurname()},
      {"adress", person.getAdress()}, {"index", person.getIndex()},
      {"salary", person.getSalary()}, {"PESEL", person.getPESEL()},
      {"sex", person.getSex()},       {"position", person.getPosition()}};
}

void Database::generateData(const int &n) noexcept {
  auto tempGenerator = std::make_unique<RecordGenerator>();
  for (int i = 0; i < n; i++) {
    database_.push_back(tempGenerator->generateRandomRecord());
  }
}

std::shared_ptr<Person>
Database::getPtrToRecord(const int &pos) const noexcept {
  return database_.at(pos);
}
