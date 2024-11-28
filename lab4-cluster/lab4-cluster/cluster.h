#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>
#include "queue.h"


const int MAX_TASK_DURATION = 15;

struct Task
{
	int NodesRequired;
	int TactsRequired;
};

struct Statistics
{
	int TotalTasks = 0;
	int CompletedTasks = 0;
	int UncompletedTasks = 0;
	int TasksInProgress = 0;
	int TasksInQueue = 0;
	int IdleTasks = 0;
	double AvgLoad = 0.0;
	double MaxLoad = 0.0;
	int TotalTacts = 0;

	friend std::ostream& operator<<(std::ostream& os, const Statistics& stats)
	{
		os << "Cluster statistics:" << std::endl;
		os << "\tTotal tasks: " << stats.TotalTasks << std::endl;
		os << "\tCompleted tasks: " << stats.CompletedTasks << std::endl;
		os << "\tUncompleted tasks: " << stats.UncompletedTasks << std::endl;
		os << "\tTasks in progress: " << stats.TasksInProgress << std::endl;
		os << "\tTasks in queue: " << stats.TasksInQueue << std::endl;
		os << "\tIdle tasks: " << stats.IdleTasks << std::endl;
		os << "\tAverage load: " << std::fixed << std::setprecision(2) << stats.AvgLoad << '%' << std::endl;
		os << "\tMaximum load: " << stats.MaxLoad << '%' << std::endl;
		os << "\tTotal tacts: " << stats.TotalTacts << std::endl;
		return os;
	}
};
class Cluster
{
	int queue_size;
	int total_tacts;
	int cluster_nodes;
	int max_tasks_per_tact;
	double task_probability;
	bool logging = false;
	Queue<Task> TaskQueue;
	std::vector<Task> TasksInProgress;
public:
	Cluster(int queueSize, int tacts, int nodes, int maxTasks, double probability) :
		queue_size(queueSize),
		total_tacts(tacts),
		cluster_nodes(nodes),
		max_tasks_per_tact(maxTasks),
		task_probability(probability), 
		TaskQueue(queue_size)
	{
		if (queue_size < 1 || cluster_nodes < 1 || max_tasks_per_tact < 1 || task_probability < 0.0 || task_probability > 1.0 || total_tacts < 1)
			throw std::invalid_argument("Invalid parameters");
	}
	void EnableLogging(bool flag)
	{ 
		logging = flag; 
	}
	Task GenerateTask() const;
	Statistics RunSimulation();
private:
	void Log(const std::string& message) const;
};