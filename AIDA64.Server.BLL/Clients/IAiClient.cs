namespace AIDA64.Server.BLL.Clients
{
    public interface IAiClient
    {
        Task<string> SendAsync(string? message, CancellationToken token = default);
    }

}
