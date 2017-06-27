from django.shortcuts import render, redirect
from django.contrib.auth import get_user_model
from django.db.models import Q
from django.views.generic import DetailView
from scripts.repoclone import clone_repo
from .models import Executable
from scripts.make_ps import make_ps

CLIENT_ID = '90e918eda87296f5cf1368be3ee840b92a7ac4adad46385da51fcced164da76b'
# def PushSwapHome(request):
#     return render(request, "pushswap42/detail.html'", {})
class PushSwapHome(DetailView):
    
    def get(self, request, *args, **kwargs):
        model = Executable.objects.all()
        if (request.GET.get('code')):
            return render(request, "repo.html", {"object": model})
        else:
            return render(request, "signin.html", {"object": model})

# def success_login(request):
#     print('SUCCESS')
#     if(request.GET.get('code')):
#         print('SUCCESS')
        
# def error_login(request):
#     print('ERROR')
#     if(request.GET.get('error')):
#         print('ERROR')

def request_page(request):
    model = Executable.objects.all()
    if(request.GET.get('TestBut')):
        clone_repo(request.GET.get("git_url"))
        make_ps()
    return render(request, "repo.html", {"object": model})
 
def login_page(request):
    if(request.GET.get('Login')):
        url = 'https://api.intra.42.fr/oauth/authorize?client_id=' + str(CLIENT_ID)
        url += '&redirect_uri=https%3A%2F%2Fpushswap42-ach5910.c9users.io%2F&response_type=code'
        return redirect(url)
        
    # queryset = PushSwap.objects.all()
    # template_name = 'pushswap42/detail.html'
    # def get(self, request, *args, **kwargs):
    #     print("Search View get")
    #     query = request.GET.get("q")
    #     qs = None
    #     if query:
    #         qs = User.objects.filter(
    #             Q(username__icontains=query)
    #             )
    #     context = {"users": qs}
    #     return render(request, "search.html", context)