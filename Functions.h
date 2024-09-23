#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stack>
#include <set>
#include <algorithm> 
#include <numeric> 
#include <fstream> 

#include "Manager.h" // + Customer.h + Trip.h + Person.h +  <iostream> + <string> + <vector> + <list> 


// ���������, ��� ����� ��'���� "����������"
struct Order {
	int year_of_booking; // ���� ��������� ������
	std::string country;// ��'� �볺���, ���� ������� �� ������
	std::string name_of_trip;// ��'� �볺���, ���� ������� �� ������
	std::string name_of_customer;// ��'� �볺���, ���� ������� �� ������
	int duration; // ��������� ������
	double price; // ������� ������
	Order(int year_of_booking, std::string country, std::string name_of_trip, std::string name_of_customer, int duration, double price)
	{
		this->year_of_booking = year_of_booking;
		this->country = country;
		this->name_of_trip = name_of_trip;
		this->name_of_customer = name_of_customer;
		this->duration = duration;
		this->price = price;
	}
};
// ��������� ��� ����� ���������� ��� ������������� �����
struct MostPopularCountries {
	std::vector<std::string> names_of_most_poular_countries; // ������ ���� ����, � �� ���� ������� �������� ������� ����
	int year_of_bought_trips;// �� ����� ����, � ������������� �����
	int count_of_bought_trips_in_most_popular_country_by_year;// ������� �������� ����, � ������������� �����
	int count_of_bought_all_trips_by_year;/// �������� ������� ��� �������� ������ �� ������ ��
};


// ������������� ����������
using ListSharedsManager_t = std::list<std::shared_ptr<Manager>>;
using ListSharedsCustomer_t = std::list<std::shared_ptr<Customer>>;
using ListSharedsTrip_t = std::list<std::shared_ptr<Trip>>;

using manager_list_iter_t = std::list<std::shared_ptr<Manager>>::iterator;
using customer_list_iter_t = std::list<std::shared_ptr<Customer>>::iterator;
using trip_list_iter_t = std::list<std::shared_ptr<Trip>>::iterator;



using CountriesList_Count_Year_AllCountYear = std::pair <std::pair<std::vector<std::string>, int>, std::pair<int, int>>;


// ������� ������� ��������
void Start(ListSharedsManager_t& Managers, ListSharedsCustomer_t& Customers, ListSharedsTrip_t& Trips);

// ������� ������� ���������� �����������
void Interface(ListSharedsManager_t& Managers, ListSharedsCustomer_t& Customers, ListSharedsTrip_t& Trips, 
	std::string managersDataPath = "Managers.txt",
	std::string customersDataPath = "Customers.txt",
	std::string tripsDataPath = "Trips.txt",
	std::string ordersPath = "Orders.txt",
	std::string historyDataPath = "History.txt");



//--------------------------------------------------------------------------------------------------------------------------------------------



// 0 ������� �������

//0.1 ���� ������ ���������, �볺���, ������, ����.
template<typename T>
void ShowListOfCollectionElementNames(const std::list<std::shared_ptr<T>>& Collection) {
	if (Collection.empty())
		return;

	int index = 1;
	for (auto& element : Collection) {
		std::cout << index << ") ";
		std::cout << element->GetFullName() << " \n";
		index++;
	}
}

//0.2 ��������� ������ �� ����� ������ ������� "dd/mm/yyyy"
int GetDateDifference(const std::string firstDate, const std::string secondDate = "today");

//0.3 �������, ��� ���������� ����� ����� ��� ������� �����
template<typename T>
void ValidatedInput(T& val);

//0.4 ����� ����������� � ����.txt
void SaveMessage(const std::string msg, const std::string path = "History.txt");

//0.5 �������� ������ 
void ClearConsole(); 

//0.6 ��������� ������� ��������� (�� ���� ��� ��� �� �����)
int GetCountOfOrders(const int year = 0, const std::string pathToFile = "Orders.txt");

//0.7 ���������� ����� ��� ���������� � ����.txt
void SaveOrderDataToFile(const int year_of_booking, const std::string country, const std::string name_of_trip, const std::string name_of_customer, const int duration, const double price, const std::string pathToFile = "Orders.txt");

//0.8 ���������� ����� ��� ���������� � ����.txt
void ReadOrdersDataFromFile(std::stack<std::string>& Collection, const std::string pathToFile);


//--------------------------------------------------------------------------------------------------------------------------------------------



// 1 ������� ���������:


//1.1 ���� ����� ���������� ��� ���������, ��� ����������� ����� 
void ShowFullInfoForEditManager(const manager_list_iter_t& manager);

//1.2 ����������� ����� ��� ��������� 
void EditManager(manager_list_iter_t& manager, const int fieldIndex, const std::string value);

//1.3 ���������� ����� ��� ��������� � ����.txt 
void SaveManagersData(const ListSharedsManager_t& ManagersCollection, const std::string path = "Managers.txt");

//1.4 ���������� ����� ��� ��������� � ����.txt 
void ReadManagersData(ListSharedsManager_t& ManagersCollection, const std::string path = "Managers.txt");



//--------------------------------------------------------------------------------------------------------------------------------------------



// 2 ������� �볺���:

//2.1 ���� ����� ���������� ��� �볺���, ��� ����������� ����� 
void ShowFullInfoForEditCustomer(const customer_list_iter_t& customer);

//2.2 ����������� ����� ��� �볺��� 
void EditCustomer(customer_list_iter_t& customer, const int fieldIndex, const std::string value);

//2.3 ���� ������ �볺���, �� �������� ������, �� ����� �����  
void ShowListOfCustomerNamesByCountry(const ListSharedsCustomer_t& CustomersCollection, const std::string country);

//2.4 ���� ������ �볺���, �� �� ����� ������. 
void ShowListOfCustomersWithoutTripNames(const ListSharedsCustomer_t& CustomersCollection);

//2.5 ���� ������ �볺���, �� ����� ������. 
void ShowListOfCustomersWithTripNames(const ListSharedsCustomer_t& CustomersCollection);

//2.6 ��������� ������� �볺���, �� ����� ������. 
std::pair<size_t, std::vector<int>> GetCountOfCustomersWithTrip(const ListSharedsCustomer_t& CustomersCollection);

//2.7 ��������� ������� �볺���, �� �� ����� ������. 
std::pair<size_t, std::vector<int>> GetCountOfCustomersWithoutTrip(const ListSharedsCustomer_t& CustomersCollection);

//2.8 ���������� ����� ��� �볺��� � ����.txt 
void SaveCustomersData(const ListSharedsCustomer_t& CustomersCollection, const std::string path = "Customers.txt");

//2.9 ���������� ����� ��� �볺��� � ����.txt 
void ReadCustomersData(ListSharedsCustomer_t& CustomersCollection, const ListSharedsTrip_t& Trips, const std::string path = "Customers.txt");



//--------------------------------------------------------------------------------------------------------------------------------------------



// 3 ������� �������:

//3.1 ���� ����� ���������� ��� ������, ��� ����������� ����� 
void ShowFullInfoForEditTrip(const trip_list_iter_t& trip);

//3.2 ����������� ����� ��� ������ 
void EditTrip(trip_list_iter_t& trip, const int fieldIndex, const std::string value);

//3.3 ���� ������ ���������� ������. 
void ShowListOfUnboughtTripNames(const ListSharedsTrip_t& Trips);

//3.4 ���� ������ �������� ������. 
void ShowListOfPurchasedTripNames(const ListSharedsTrip_t& Trips);

//3.5 ��������� ������� ���������� ������  
std::pair<size_t, std::vector<int>> GetCountOfUnboughtTrips(const ListSharedsTrip_t& Trips);

//3.6 ��������� ������� �������� ������  
std::pair<size_t, std::vector<int>> GetCountOfPurchasedTrips(const ListSharedsTrip_t& Trips);

//3.7 ��������� ������ ����, �������� ������
std::vector<std::string> GetCountriesOfBoughtTrips(const ListSharedsTrip_t& Trips, const int year = 0);

//3.8 ��������� ���������� �������� ������� ������
int GetAveragePriceOfTrips(const ListSharedsTrip_t& Trips, const int year = 0, std::string path = "Orders.txt");

//3.9 ��������� ���������� �������� ��������� ������ 
double GetAverageDurationOfTrips(const ListSharedsTrip_t& Trips, const int year = 0, std::string path = "Orders.txt");

//3.10 ����� ����� ������ �� id 
std::shared_ptr<Trip> FindTripById(const ListSharedsTrip_t& Collection, const int personal_id);

//3.11 ����� ����, �� ����� ��������� �����.����������� �������� : (�����, ����(�������, ��))
MostPopularCountries FindMostPupularCountries(const std::list<std::shared_ptr<Trip>>& trips_collection, const int year, const std::string path_to_file_with_orders = "Orders.txt");

//3.12 ���� ����, �� ����� ��������� �����. 
void ShowMostPupularCountries(const MostPopularCountries& data);

//3.13 ���������� ����� ��� ������ � ����.txt
void SaveTripsData(const ListSharedsTrip_t& Trips, const std::string path = "Trips.txt");

//3.14 ���������� ����� ��� ������ � ����.txt 
void ReadTripsData(std::list<std::shared_ptr<Trip>>& Trips, const std::string path = "Trips.txt");

#endif // !FUNCTIONS_H