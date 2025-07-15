using AIDA64.Server.BLL.Clients;
using Microsoft.AspNetCore.Mvc;

namespace AIDA64.Server.Controllers
{
    [ApiController]
    [Route("[controller]")]
    public class AiController : ControllerBase
    {
        private readonly IAiClient _client = default!;
        private readonly ILogger<AiController> _logger = default!;


        public AiController(IAiClient client, ILogger<AiController> logger)
        {
            _client = client;
            _logger = logger;
        }

        [HttpGet]
        public async Task<string> Get([FromQuery] string? message, CancellationToken token)
        {
            return await _client.SendAsync(message, token);
        }
    }
}
