from git import Repo

def clone_repo(url):
    print("\n\n" + str(url) + "\n\n")
    Repo.clone_from(url, "../repo/")
    