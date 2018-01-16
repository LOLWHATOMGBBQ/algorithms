
import gym
from gym import wrappers
env = gym.make('Copy-v0')
env = wrappers.Monitor(env, '/tmp/copy-v0', force=True)
for i_episode in range(500):
    observation = env.reset()
    for t in range(100):
        action = (1,1,observation)
        observation, reward, done, info = env.step(action)
        if done:
            print("Episode finished after {} timesteps".format(t+1))
            break

print "ENDED"
env.render()
