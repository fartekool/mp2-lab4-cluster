#include "cluster.h"

Task Cluster::GenerateTask() const
{	
	Task task;
	task.NodesRequired = 1 + rand() % cluster_nodes;
	task.TactsRequired = 1 + rand() % MAX_TASK_DURATION;
	return task;
}

void Cluster::Log(const std::string& message) const
{
	if (logging)
		std::cout << message << std::endl;
}

Statistics Cluster::RunSimulation()
{
	Statistics stats;
	stats.TotalTacts = total_tacts;
	int free_nodes = cluster_nodes;
	stats.MaxLoad = 0.0;

	for (int current_tact = 0; current_tact < total_tacts; ++current_tact)
	{
		Log("Tact " + std::to_string(current_tact + 1));

		for (int i = 0; i < max_tasks_per_tact; ++i)
		{
			if ((double(rand()) / double(RAND_MAX)) <= task_probability)
			{
				Task new_task = GenerateTask();
				if (!TaskQueue.Full())
				{
					TaskQueue.Push(new_task);
					++stats.TotalTasks;
					Log("\tTask created: nodes = " + std::to_string(new_task.NodesRequired) + ", tacts = " + std::to_string(new_task.TactsRequired));
				}
				else
					Log("\tTask cancelled");
			}
		}

		while (!TaskQueue.Empty() && free_nodes >= TaskQueue.Top().NodesRequired)
		{
			Task task = TaskQueue.Top();
			TaskQueue.Pop();
			TasksInProgress.push_back(task);
			free_nodes -= task.NodesRequired;
			Log("\tTask has been transferred for execution: nodes = " + std::to_string(task.NodesRequired));
		}

		for (auto it = TasksInProgress.begin(); it != TasksInProgress.end(); )
		{
			--it->TactsRequired;
			if (it->TactsRequired == 0)
			{
				free_nodes += it->NodesRequired;
				++stats.CompletedTasks;
				Log("\tTask completed: freed nodes = " + std::to_string(it->NodesRequired));
				it = TasksInProgress.erase(it);
			}
			else
				++it;
		}

		if (TasksInProgress.empty())
			++stats.IdleTasks;
		double current_load = (double(cluster_nodes - free_nodes) / double(cluster_nodes)) * 100;
		stats.AvgLoad += current_load;
		if (current_load > stats.MaxLoad)
			stats.MaxLoad = current_load;

		Log("\tFree nodes: " + std::to_string(free_nodes));
	}

	stats.TasksInQueue = TaskQueue.Size();
	stats.TasksInProgress = TasksInProgress.size();
	stats.UncompletedTasks = stats.TotalTasks - stats.CompletedTasks;
	stats.AvgLoad /= total_tacts;

	return stats;
}