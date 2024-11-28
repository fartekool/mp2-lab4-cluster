#include "pch.h"
#include "../lab4-cluster/cluster.h"
#include "../lab4-cluster/cluster.cpp"

TEST(Cluster, can_create_cluster_with_valid_parameters)
{
	ASSERT_NO_THROW(Cluster cluster(1, 50, 32, 5, 0.7));
}

TEST(Cluster, cant_create_cluster_with_invalid_parameters)
{
	EXPECT_ANY_THROW(Cluster cluster(-1, 50, 32, 5, 0.7));
	EXPECT_ANY_THROW(Cluster cluster(1, -1, 32, 5, 0.7));
	EXPECT_ANY_THROW(Cluster cluster(1, 50, -32, 5, 0.7));
	EXPECT_ANY_THROW(Cluster cluster(1, 50, 32, 0, 0.7));
	EXPECT_ANY_THROW(Cluster cluster(1, 50, 32, 5, -0.1));
	EXPECT_ANY_THROW(Cluster cluster(1, 50, 32, 5, 1.1));
	EXPECT_ANY_THROW(Cluster cluster(-8, 0, -9, -8, 1.1));
}

TEST(Cluster, generated_task_has_valid_range_of_parameters)
{	
	srand(time(NULL));
	Cluster cluster(10, 50, 20, 5, 0.5);
	Task task1 = cluster.GenerateTask();
	Task task2 = cluster.GenerateTask();
	Task task3 = cluster.GenerateTask();
	Task task4 = cluster.GenerateTask();
	Task task5 = cluster.GenerateTask();
	Task task6 = cluster.GenerateTask();
	Task task7 = cluster.GenerateTask();
	Task task8 = cluster.GenerateTask();
	Task task9 = cluster.GenerateTask();
	Task task10 = cluster.GenerateTask();

	EXPECT_GE(task1.NodesRequired, 1);
	EXPECT_GE(task2.NodesRequired, 1);
	EXPECT_GE(task3.NodesRequired, 1);
	EXPECT_GE(task4.NodesRequired, 1);
	EXPECT_GE(task5.NodesRequired, 1);
	EXPECT_GE(task6.NodesRequired, 1);
	EXPECT_GE(task7.NodesRequired, 1);
	EXPECT_GE(task8.NodesRequired, 1);
	EXPECT_GE(task9.NodesRequired, 1);
	EXPECT_GE(task10.NodesRequired, 1);

	EXPECT_LE(task1.NodesRequired, 20);
	EXPECT_LE(task2.NodesRequired, 20);
	EXPECT_LE(task3.NodesRequired, 20);
	EXPECT_LE(task4.NodesRequired, 20);
	EXPECT_LE(task5.NodesRequired, 20);
	EXPECT_LE(task6.NodesRequired, 20);
	EXPECT_LE(task7.NodesRequired, 20);
	EXPECT_LE(task8.NodesRequired, 20);
	EXPECT_LE(task9.NodesRequired, 20);
	EXPECT_LE(task10.NodesRequired, 20);

	EXPECT_GE(task1.TactsRequired, 1);
	EXPECT_GE(task2.TactsRequired, 1);
	EXPECT_GE(task3.TactsRequired, 1);
	EXPECT_GE(task4.TactsRequired, 1);
	EXPECT_GE(task5.TactsRequired, 1);
	EXPECT_GE(task6.TactsRequired, 1);
	EXPECT_GE(task7.TactsRequired, 1);
	EXPECT_GE(task8.TactsRequired, 1);
	EXPECT_GE(task9.TactsRequired, 1);
	EXPECT_GE(task10.TactsRequired, 1);

	EXPECT_LE(task1.TactsRequired, MAX_TASK_DURATION);
	EXPECT_LE(task2.TactsRequired, MAX_TASK_DURATION);
	EXPECT_LE(task3.TactsRequired, MAX_TASK_DURATION);
	EXPECT_LE(task4.TactsRequired, MAX_TASK_DURATION);
	EXPECT_LE(task5.TactsRequired, MAX_TASK_DURATION);
	EXPECT_LE(task6.TactsRequired, MAX_TASK_DURATION);
	EXPECT_LE(task7.TactsRequired, MAX_TASK_DURATION);
	EXPECT_LE(task8.TactsRequired, MAX_TASK_DURATION);
	EXPECT_LE(task9.TactsRequired, MAX_TASK_DURATION);
	EXPECT_LE(task10.TactsRequired, MAX_TASK_DURATION);

}

TEST(Cluster, valid_statistics_when_probability_is_zero)
{	
	srand(time(NULL));
	Cluster cluster(10, 50, 20, 5, 0.0);
	Statistics stats = cluster.RunSimulation();

	EXPECT_EQ(stats.TotalTasks, 0);
	EXPECT_EQ(stats.CompletedTasks, 0);
	EXPECT_EQ(stats.UncompletedTasks, 0);
	EXPECT_EQ(stats.TasksInProgress, 0);
	EXPECT_EQ(stats.TasksInQueue, 0);
	EXPECT_EQ(stats.IdleTasks, 50);
	EXPECT_EQ(stats.AvgLoad, 0.0);
	EXPECT_EQ(stats.MaxLoad, 0.0);
	EXPECT_EQ(stats.TotalTacts, 50);

}

TEST(Cluster, valid_statistics)
{	
	srand(time(NULL));
	Cluster cluster(10, 50, 20, 5, 0.5);
	Statistics stats = cluster.RunSimulation();


	EXPECT_GE(stats.TotalTasks, stats.CompletedTasks);
	EXPECT_GE(stats.UncompletedTasks, 0);
	EXPECT_GE(stats.IdleTasks, 0);
	EXPECT_LE(stats.MaxLoad, 100.);

}