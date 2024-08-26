#pragma once
#include "PESELValidator.hpp"
#include "RecordGenerator.hpp"

class Database {
public:
  void addStudent(const std::string &name, const std::string &surname,
                  const std::string &adress, const int &index,
                  const std::string &PESEL, const Sex &sex,
                  const Position &position) noexcept;
  void addEmployee(const std::string &name, const std::string &surname,
                   const std::string &adress, const float &salary,
                   const std::string &PESEL, const Sex &sex,
                   const Position &position) noexcept;
  std::string returnRecordsAsString();
  std::string returnRecordsWithGivenSurname(std::string surname);
  std::string returnRecordWithGivenPesel(std::string pesel);
  std::vector<std::shared_ptr<Person>>
  findBySurname(const std::string &surname) const noexcept;
  std::shared_ptr<Person> findByPESEL(const std::string &PESEL) const noexcept;
  void sortBySurname() noexcept;
  void sortByPESEL() noexcept;
  void sortBySalary() noexcept;
  std::string returnEmployeesSortedBySalary();
  bool checkIfGivenIndexExist(const int& index);
  bool removeByIndex(const int &index) noexcept;
  bool modifySalary(const std::string &PESEL, const float &newSalary) noexcept;
  bool validatePESEL(const std::string &PESEL) const noexcept;
  void loadToJson() noexcept;
  void saveToJson() const noexcept;
  void generateData(const int &n) noexcept;
  std::shared_ptr<Person> getPtrToRecord(const int &pos) const noexcept;

private:
  std::vector<std::shared_ptr<Person>> database_;
  void putRecordInSstream(std::stringstream& sstream, const std::shared_ptr<Person>& record) const noexcept;
  void toJson(nlohmann::json &j, Person &person) const noexcept;
};
